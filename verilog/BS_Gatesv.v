//You are given a four-bit input vector in[3:0]. We want to know some relationships between each bit and its neighbour:
//out_both: Each bit of this output vector should indicate whether both the corresponding input bit and its neighbour to the left (higher index) are '1'. For example, out_both[2] should indicate if in[2] and in[3] are both 1. Since in[3] has no neighbour to the left, the answer is obvious so we don't need to know out_both[3].
//out_any: Each bit of this output vector should indicate whether any of the corresponding input bit and its neighbour to the right are '1'. For example, out_any[2] should indicate if either in[2] or in[1] are 1. Since in[0] has no neighbour to the right, the answer is obvious so we don't need to know out_any[0].
//out_different: Each bit of this output vector should indicate whether the corresponding input bit is different from its neighbour to the left. For example, out_different[2] should indicate if in[2] is different from in[3]. For this part, treat the vector as wrapping around, so in[3]'s neighbour to the left is in[0].

//最初は
module top_module( 
    input [3:0] in,
    output reg [2:0] out_both,      // 注意：只需要 3 位
    output reg [3:1] out_any,       // 注意：只需要 bits 3:1
    output reg [3:0] out_different  // 全部 4 位
);
    integer i;
    
    always @(*) begin
        // out_both: 遍历 0 到 2，计算 in[i] & in[i+1]
        for (i = 0; i < 3; i = i + 1) begin
            out_both[i] = in[i] & in[i+1];
        end
        
        // out_any: 遍历 1 到 3，计算 in[i] | in[i-1]
        for (i = 1; i < 4; i = i + 1) begin
            out_any[i] = in[i] | in[i-1];
        end
        
        // out_different: 遍历 0 到 2，计算 in[i] ^ in[i+1]
        for (i = 0; i < 3; i = i + 1) begin
            out_different[i] = in[i] ^ in[i+1];
        end
        // 对于 out_different[3]，需要 wrap-around：in[3] 与 in[0] 的比较
        out_different[3] = in[3] ^ in[0];
    end
endmodule