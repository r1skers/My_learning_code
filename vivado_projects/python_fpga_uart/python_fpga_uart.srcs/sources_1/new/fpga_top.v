// 模块：顶层文件
// 功能：连接 uart_rx 和 command_parser
module fpga_top(
    input clk_in,   // FPGA芯片的全局时钟输入
    input rxd_in,   // FPGA芯片的串口接收引脚
    output led_out  // FPGA芯片的LED输出引脚
    );
    
    // 声明“电线”(wire) 来连接两个模块
    wire [7:0] uart_data;  // 用于传输解析出的8位数据
    wire       uart_valid; // 用于传输 "数据有效" 信号
    
    // 实例化UART接收器
    // 就像在电路板上放一个 uart_rx 芯片
    uart_rx i_uart_rx (
        .clk        (clk_in),     // 把全局时钟连到 uart_rx 的 clk
        .rxd        (rxd_in),     // 把 rxd 引脚连到 uart_rx 的 rxd
        .data_out   (uart_data),  // uart_rx 的输出连到 "uart_data" 电线
        .data_valid (uart_valid)  // uart_rx 的输出连到 "uart_valid" 电线
    );
    
    // 实例化指令解析器
    // 就像在电路板上放一个 command_parser 芯片
    command_parser i_parser (
        .clk        (clk_in),     // 把全局时钟也连到 parser 的 clk
        .rst        (0),          // 简单起见，复位信号rst直接接地 (0)
        .data_in    (uart_data),  // "uart_data" 电线连到 parser 的输入
        .data_valid (uart_valid), // "uart_valid" 电线连到 parser 的输入
        .led_out    (led_out)     // parser 的输出连到 FPGA 的 led 引脚
    );
    
endmodule