`timescale 1ns / 1ps
// timescale 定义了仿真时间和精度

module tb_mux_2_to_1();

    // 1. 准备输入信号的"篮子" (用reg类型)
    reg a;
    reg b;
    reg sel;

    // 2. 准备接收输出信号的"篮子" (用wire类型)
    wire y;

    // 3. 把我们的设计(DUT)放到测试平台里，并连线
    //    这叫做 "实例化" (Instantiation)
    mux_2_to_1  dut (
        .a(a),      // 将测试平台的 a 连接到 dut 的 a 端口
        .b(b),      // 将测试平台的 b 连接到 dut 的 b 端口
        .sel(sel),  // 将测试平台的 sel 连接到 dut 的 sel 端口
        .y(y)       // 将测试平台的 y 连接到 dut 的 y 端口
    );

    // 4. 编写测试流程，给输入信号赋值
    initial begin
        // 在 0 时刻，给 a, b, sel 一个初始值
        a = 0;
        b = 1;
        sel = 0;

        // 等待10个时间单位 (10ns)
        #10;
        // 此时我们期望 y 的值应该和 a 一样，为 0

        // 改变选择信号 sel
        sel = 1;
        
        // 再等待10个时间单位
        #10;
        // 此时我们期望 y 的值应该和 b 一样，为 1

        // 改变输入信号 a
        a = 1;
        b = 0;
        sel = 0;
        
        #10;
        // 此时我们期望 y 的值应该和 a 一样，为 1
        
        sel = 1;
        
        #10;
        // 此时我们期望 y 的值应该和 b 一样，为 0

        // 等待一段时间后，结束仿真
        #10;
        $finish;
    end

endmodule