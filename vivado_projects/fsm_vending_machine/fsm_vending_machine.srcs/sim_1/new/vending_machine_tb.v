// `timescale 定义了仿真单位和精度
`timescale 1ns / 1ps

// Testbench 模块没有输入输出端口
module vending_machine_tb;

    // 1. 信号声明
    // reg 类型用来产生激励信号，作为被测试模块的 input
    reg clk;
    reg rst;
    reg coin_in;
    reg select;

    // wire 类型用来接收被测试模块的 output
    wire dispense;

    // 2. 实例化你的设计 (DUT: Device Under Test)
    // 这里的 vending_machine 要和你的模块名完全一致
    vending_machine uut (
        .clk(clk),
        .rst(rst),
        .coin_in(coin_in),
        .select(select),
        .dispense(dispense)
    );

    // 3. 产生时钟信号
    // 定义一个 10ns 的时钟周期 (5ns高电平, 5ns低电平)
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 每 5ns 翻转一次 clk
    end

    // 4. 产生激励信号序列
    initial begin
        // 初始化所有输入
        rst = 1;      // 初始时，给一个高电平复位
        coin_in = 0;
        select = 0;
        
        // ---- 开始测试 ----
        #20;          // 等待 20ns
        rst = 0;      // 释放复位，状态机开始正常工作
        
        #20;          // 等待
        coin_in = 1;  // 模拟投币
        
        #10;          // 投币信号持续一个时钟周期
        coin_in = 0;
        
        #20;          // 等待几个周期
        select = 1;   // 模拟按下选择按钮
        
        #10;          // 选择信号持续一个时钟周期
        select = 0;
        
        #50;          // 等待一段时间，观察后续状态
        
        // ---- 结束仿真 ----
        $finish;      // 调用系统任务 $finish 来结束仿真
    end

endmodule