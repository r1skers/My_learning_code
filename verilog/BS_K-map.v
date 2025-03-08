//默认横的表示ab，纵的表示cd,顺序为格雷码顺序;
// 00 01 11 10
//00 0 1 0 1
//01 1 0 1 0
//11 0 1 0 1
//10 1 0 1 0

//常规写法过于麻烦，不在此赘述
//逻辑门
module karnaugh_map(
    input a,
    input b,
    input c,
    input d,
    output out
);
    assign out = a ^ b ^ c ^ d; // 四个变量的异或
endmodule


//观察卡诺图发现有奇数个1就输出1
module top_module(
    input a,
    input b,
    input c,
    input d,
    output out  );
    wire w=a+b+c+d;
    assign out=w%2;

endmodule
