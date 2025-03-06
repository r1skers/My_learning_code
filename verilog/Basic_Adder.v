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