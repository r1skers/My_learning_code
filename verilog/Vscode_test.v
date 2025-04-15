`timescale 1ns/10ps
module test (a,b);
    input[7:0]a;
    output[7:0]b;
    wire[7:0] y;
    assign y={a[7],~a[6:0]+1};
    assign b=a[7]?y:a;
endmodule

// //测试模块
module test_tb;
    reg[7:0]a_in;
    wire[7:0]b_out;
    test test(.a(a_in),.b(b_out));
    initial begin
       a_in<=0;
       #3000 $stop;
    end
    always #10 a_in<=a_in+1; //每10ns加1
endmodule