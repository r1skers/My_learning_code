// 模块：Testbench for fpga_top
`timescale 1ns / 1ps // 定义仿真时间单位：1ns 精度，1ps 步进

module tb_fpga_top; // Testbench 模块没有输入输出引脚

    // 1. 定义内部信号
    reg clk_tb;   // reg 类型，因为我们要驱动它 (产生时钟)
    reg rxd_tb;   // reg 类型，因为我们要驱动它 (模拟Python)
    wire led_tb;  // wire 类型，因为我们只是观察它 (FPGA的输出)

    // 2. 实例化我们的 "被测设计" (DUT: Device Under Test)
    // 把我们刚才设计的 fpga_top 模块“放”到测试台里
    fpga_top DUT (
        .clk_in(clk_tb),   // 把 tb 的时钟连到 DUT 的时钟
        .rxd_in(rxd_tb),   // 把 tb 的 rxd 连到 DUT 的 rxd
        .led_out(led_tb)  // 把 DUT 的 led 输出连到 tb 的 led 观察线
    );


    // 3. 生成时钟
    // 我们假设一个 50MHz 的时钟 (周期 = 20ns)
    initial begin
        clk_tb = 0;
        forever #10 clk_tb = ~clk_tb; // 每10ns翻转一次电平
    end

    // 4. 定义一个 "任务" (task)，用于模拟发送一个字节
    // 这等同于 Python 里的 ser.write(b'X')
    
    // 9600 波特率 = 每 bit 持续 1 / 9600 秒 = 104166.66 ns
    // 我们在仿真时取整数 104167 ns
    localparam BIT_PERIOD = 104167; 
    
    task send_byte;
        input [7:0] data; // 接收一个8位的字节
        begin
            // 1. 起始位 (Start Bit) - 低电平
            rxd_tb <= 0;
            #(BIT_PERIOD); // 保持一个 bit 的时间
            
            // 2. 8位数据 (Data Bits) - 从第0位(LSB)开始
            rxd_tb <= data[0];
            #(BIT_PERIOD);
            rxd_tb <= data[1];
            #(BIT_PERIOD);
            rxd_tb <= data[2];
            #(BIT_PERIOD);
            rxd_tb <= data[3];
            #(BIT_PERIOD);
            rxd_tb <= data[4];
            #(BIT_PERIOD);
            rxd_tb <= data[5];
            #(BIT_PERIOD);
            rxd_tb <= data[6];
            #(BIT_PERIOD);
            rxd_tb <= data[7]; // 第7位 (MSB)
            #(BIT_PERIOD);
            
            // 3. 停止位 (Stop Bit) - 高电平
            rxd_tb <= 1;
            #(BIT_PERIOD);
        end
    endtask


    // 5. 仿真激励 (Test Stimulus)
    // 这是仿真的“剧本”，模拟Python脚本的行为
    initial begin
        // 初始化：rxd 串口空闲时是高电平
        rxd_tb = 1;
        #1000;      // 等待 1000ns，让系统稳定
        
        // --- 剧本开始 ---
        
        // 测试1：发送 "ON" (ASCII 'O'=h4F, 'N'=h4E)
        // 对应 Python: ser.write(b'ON')
        send_byte(8'h4F); // 'O'
        send_byte(8'h4E); // 'N'
        
        // 发送完 "ON"，我们期望 led_tb 变为 1
        #5000000; // 等待 5,000,000 ns (5ms)，让我们能在波形上看到结果
        
        
        // 测试2：发送 "OFF" (ASCII 'O'=h4F, 'F'=h46)
        // 对应 Python: ser.write(b'OFF')
        send_byte(8'h4F); // 'O'
        send_byte(8'h46); // 'F'
        send_byte(8'h46); // 'F'
        
        // 发送完 "OFF"，我们期望 led_tb 变为 0
        #5000000; // 再等待 5ms
        
        
        // 测试3：发送错误指令 "OFN" (应该没反应)
        send_byte(8'h4F); // 'O'
        send_byte(8'h46); // 'F'
        send_byte(8'h4E); // 'N'
        
        // 期望 led_tb 保持为 0
        #5000000; // 再等待 5ms
        
        // 测试4：再次发送 "ON"
        send_byte(8'h4F); // 'O'
        send_byte(8'h4E); // 'N'
        
        // 期望 led_tb 再次变为 1
        #5000000; // 再等待 5ms
        
        
        // --- 剧本结束 ---
        $stop; // 停止仿真
    end

endmodule