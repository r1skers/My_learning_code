module seven_segment_decoder (
    // 输入端口：4位的BCD码
    input  wire [3:0] bcd_in,      
    
    // 输出端口：7位的段控制信号
    
    output reg  [6:0] segments_out 
);

    // 使用 always @(*) 块来描述组合逻辑
    // * 代表敏感列表里包含所有在块内读取的信号（这里是 bcd_in）
    // 只要 bcd_in 发生变化，就立刻重新执行这个块
    always @(*) begin
        // 使用 case 语句来检查 bcd_in 的值
        case (bcd_in)
            // BCD -> {g,f,e,d,c,b,a}
            4'b0000: segments_out = 7'b0111111; // 显示 '0'
            4'b0001: segments_out = 7'b0000110; // 显示 '1'
            4'b0010: segments_out = 7'b1011011; // 显示 '2'
            4'b0011: segments_out = 7'b1001111; // 显示 '3'
            4'b0100: segments_out = 7'b1100110; // 显示 '4'
            4'b0101: segments_out = 7'b1101101; // 显示 '5'
            4'b0110: segments_out = 7'b1111101; // 显示 '6'
            4'b0111: segments_out = 7'b0000111; // 显示 '7'
            4'b1000: segments_out = 7'b1111111; // 显示 '8'
            4'b1001: segments_out = 7'b1101111; // 显示 '9'
            
            // 对于所有其他无效输入 (10 到 15), 执行默认操作
            // 这可以防止生成不希望的锁存器(latch)，是一个好的设计习惯
            default: segments_out = 7'b0000000; // 全都熄灭
            
        endcase
    end

endmodule


