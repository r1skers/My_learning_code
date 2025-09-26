// 1. 定义仿真时间单位和精度。1ns是单位，1ps是精度。
`timescale 1ns / 1ps

// 2. 定义Testbench模块，模块名可以任意，但最好有tb_前缀
module tb_simple_counter();

    // 3. 准备驱动DUT的信号
    // 要连接到DUT输入端的信号，在Testbench里必须是reg类型
    reg clk;
    reg rst_n;

    // 从DUT输出端引出的信号，在Testbench里必须是wire类型
    wire [3:0] count_out;


    // 4. 实例化你的设计模块 (DUT - Device Under Test)
    // 把上面准备好的reg和wire信号，像电线一样连接到DUT的端口上
    simple_counter u_dut (
        .clk        (clk),
        .rst_n      (rst_n),
        .count_out  (count_out)
    );


    // 5. 产生时钟信号 (clk)
    // initial块里的代码从仿真0时刻开始执行一次
    initial begin
        clk = 0; // 初始时钟为0
    end
    // always块让时钟永久地翻转下去
    // #5 表示延迟5个时间单位(5ns)，所以时钟周期是10ns (100MHz)
    always #5 clk = ~clk;


    // 6. 产生其他的激励信号 (rst_n)
    initial begin
        // 仿真开始时，让系统处于复位状态
        rst_n = 0;

        // 保持复位20ns
        #20;

        // 释放复位，计数器应该从0开始计数
        rst_n = 1;

        // 让仿真再运行200ns，足够我们观察计数过程
        #200;

        // 结束仿真
        $finish;
    end

endmodule