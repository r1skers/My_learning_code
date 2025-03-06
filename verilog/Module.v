//Module A is supposed to implement the function z = (x^y) & x. 
module A(
    input x,y,
    output z);
    assign z=(x^y)&x;
endmodule
module top_module (input x, input y, output z);
    A imp(
        .x(x),
        .y(y),
        .z(z));
endmodule
