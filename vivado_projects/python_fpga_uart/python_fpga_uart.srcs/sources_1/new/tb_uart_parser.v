
`timescale 1ns/1ps
// Self-checking testbench: uart_rx + command_parser integrated
module tb_uart_parser;
  // ====== Parameters for simulation ======
  localparam integer CLK_FREQ_HZ   = 100_000_000;   // 100 MHz sim clock
  localparam integer CLKS_PER_BIT  = 16;            // keep small in sim; 100e6/16 = 6.25 Mbps effective UART
  localparam integer TCLK_NS       = 10;            // 100 MHz => 10 ns

  // ====== Clock ======
  reg clk = 1'b0;
  always #(TCLK_NS/2) clk = ~clk;

  // ====== DUT wiring ======
  reg        rst = 1'b1;
  reg        rxd = 1'b1;   // UART idle = 1
  wire [7:0] data;
  wire       valid;
  wire       led;

  // Instantiate user RTL (make sure these module names match your files)
  uart_rx #(.CLKS_PER_BIT(CLKS_PER_BIT)) i_rx (
    .clk        (clk),
    .rxd        (rxd),
    .data_out   (data),
    .data_valid (valid)
  );

  command_parser i_parser (
    .clk        (clk),
    .rst        (rst),
    .data_in    (data),
    .data_valid (valid),
    .led_out    (led)
  );

  // ====== UART driver tasks (LSB-first) ======
  task automatic uart_write_byte(input [7:0] b);
    integer i;
    begin
      // start bit
      rxd <= 1'b0;
      repeat (CLKS_PER_BIT) @(posedge clk);

      // data bits
      for (i = 0; i < 8; i = i + 1) begin
        rxd <= b[i];
        repeat (CLKS_PER_BIT) @(posedge clk);
      end

      // stop bit
      rxd <= 1'b1;
      repeat (CLKS_PER_BIT) @(posedge clk);
    end
  endtask

  // Frame with wrong stop bit (should be rejected by rx)
  task automatic uart_write_byte_badstop(input [7:0] b);
    integer i;
    begin
      rxd <= 1'b0; repeat (CLKS_PER_BIT) @(posedge clk); // start
      for (i = 0; i < 8; i = i + 1) begin
        rxd <= b[i]; repeat (CLKS_PER_BIT) @(posedge clk);
      end
      rxd <= 1'b0; repeat (CLKS_PER_BIT) @(posedge clk); // BAD stop
      rxd <= 1'b1; repeat (CLKS_PER_BIT) @(posedge clk); // back to idle
    end
  endtask

  // ====== Utilities ======
  task automatic expect_led(input bit exp, input [255:0] msg);
    begin
      @(posedge clk);
      if (led !== exp) begin
        $display("[ERROR] %0t ns: %s  led=%b exp=%b", $time, msg, led, exp);
        $fatal(1);
      end else begin
        $display("[OK]    %0t ns: %s  led=%b", $time, msg, led);
      end
    end
  endtask

  // ====== Test sequence ======
  initial begin
    $dumpfile("uart_parser_tb.vcd");
    $dumpvars(0, tb_uart_parser);

    // reset
    repeat (10) @(posedge clk);
    rst <= 1'b0;

    // 1) Send "ON" => LED should turn ON
    uart_write_byte("O"); // 8'h4F
    uart_write_byte("N"); // 8'h4E
    expect_led(1'b1, "After 'ON'");

    // 2) Send "OFF" => LED should turn OFF
    uart_write_byte("O");
    uart_write_byte("F");
    uart_write_byte("F");
    expect_led(1'b0, "After 'OFF'");

    // 3) Send a frame with bad stop bit: should NOT assert data_valid, so LED must not change
    uart_write_byte_badstop("O");
    uart_write_byte("N"); // parser sees only 'N' => should not toggle
    expect_led(1'b0, "After bad stop + 'N' (no change expected)");

    // 4) Random bytes shouldn't form a valid command
    uart_write_byte(8'h55);
    uart_write_byte(8'hAA);
    expect_led(1'b0, "After random bytes");

    // 5) Back-to-back frames: OFF then ON with minimal idle
    uart_write_byte("O"); uart_write_byte("F"); uart_write_byte("F");
    uart_write_byte("O"); uart_write_byte("N");
    expect_led(1'b1, "After 'OFF' then 'ON' back-to-back");

    $display("All tests passed.");
    #200;
    $finish;
  end
endmodule
