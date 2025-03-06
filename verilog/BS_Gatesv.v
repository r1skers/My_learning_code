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


//もう少し理解やすいのは
module top_module( 
    input  [3:0] in,
    output [2:0] out_both,      // bits [2:0]
    output [3:1] out_any,       // bits [3:1]
    output [3:0] out_different  // bits [3:0]
);

    // 1) out_both[i] = 1 当 in[i] 和它的左邻居 (更高index) 同时为1
    //    - out_both[2] = in[2] & in[3]
    //    - out_both[1] = in[1] & in[2]
    //    - out_both[0] = in[0] & in[1]
    assign out_both[0] = in[0] & in[1];
    assign out_both[1] = in[1] & in[2];
    assign out_both[2] = in[2] & in[3];

    // 2) out_any[i] = 1 当 in[i] 和它的右邻居 (更低index) 中有任意一个为1
    //    - out_any[3] = in[3] | in[2]
    //    - out_any[2] = in[2] | in[1]
    //    - out_any[1] = in[1] | in[0]
    //    (不需要 out_any[0])
    assign out_any[3] = in[3] | in[2];
    assign out_any[2] = in[2] | in[1];
    assign out_any[1] = in[1] | in[0];

    // 3) out_different[i] = 1 当 in[i] 和它的左邻居不同
    //    根据题意，最左边 in[3] 的左邻居 wrap around 到 in[0]
    //    - out_different[0] = (in[0] ^ in[1])
    //    - out_different[1] = (in[1] ^ in[2])
    //    - out_different[2] = (in[2] ^ in[3])
    //    - out_different[3] = (in[3] ^ in[0])  // wrap around
    assign out_different[0] = in[0] ^ in[1];
    assign out_different[1] = in[1] ^ in[2];
    assign out_different[2] = in[2] ^ in[3];
    assign out_different[3] = in[3] ^ in[0];

endmodule


//最も簡単なのは
module top_module (
	input [3:0] in,
	output [2:0] out_both,
	output [3:1] out_any,
	output [3:0] out_different
);

	// Use bitwise operators and part-select to do the entire calculation in one line of code
	// in[3:1] is this vector:   					 in[3]  in[2]  in[1]
	// in[2:0] is this vector:   					 in[2]  in[1]  in[0]
	// Bitwise-OR produces a 3 bit vector.			   |      |      |
	// Assign this 3-bit result to out_any[3:1]:	o_a[3] o_a[2] o_a[1]

	// Thus, each output bit is the OR of the input bit and its neighbour to the right:
	// e.g., out_any[1] = in[1] | in[0];	
	// Notice how this works even for long vectors.
	assign out_any = in[3:1] | in[2:0];

	assign out_both = in[2:0] & in[3:1];
	
	// XOR 'in' with a vector that is 'in' rotated to the right by 1 position: {in[0], in[3:1]}
	// The rotation is accomplished by using part selects[] and the concatenation operator{}.
	assign out_different = in ^ {in[0], in[3:1]};
	
endmodule
