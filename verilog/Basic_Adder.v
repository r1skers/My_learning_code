//half adder
module top_module( 
    input a, b,
    output cout, sum );
    assign{cout,sum}=a+b;
endmodule



//full adder
module top_module( 
    input a, b, cin,
    output cout, sum );
    assign {cout,sum}=a+b+cin;
endmodule


//3-bit binary ripple carry adder
module full_adder (
    input a, b, cin,
    output sum, cout
);
    assign sum = a ^ b ^ cin;
    assign cout = (a & b) | (b & cin) | (a & cin);
endmodule

module top_module( 
    input [2:0] a, b,
    input cin,
    output [2:0] cout,
    output [2:0] sum 
);
    // Instantiate three full adders
    full_adder fa0 (a[0], b[0], cin,   sum[0], cout[0]);
    full_adder fa1 (a[1], b[1], cout[0], sum[1], cout[1]);
    full_adder fa2 (a[2], b[2], cout[1], sum[2], cout[2]);

endmodule


//overflow(溢出检测)
module top_module (
    input [7:0] a,        // 8-bit 输入 a
    input [7:0] b,        // 8-bit 输入 b
    output [7:0] s,       // 8-bit 输出 s
    output overflow       // 溢出标志
);
    wire [8:0] sum_temp;  // 9-bit 临时结果
    assign sum_temp = a + b; // 9-bit 加法
    assign s = sum_temp[7:0]; // 低 8 位为结果

    // 溢出检测：基于符号位和进位
    assign overflow = (a[7] == b[7]) && (s[7] != a[7]);
    //Detect overflow
    //assign overflow = (~a[7] & ~b[7] & s[7]) | (a[7] & b[7] & ~s[7]);

endmodule