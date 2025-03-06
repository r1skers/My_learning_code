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