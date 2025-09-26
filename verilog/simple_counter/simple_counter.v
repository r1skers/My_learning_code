module simple_counter (
    input               clk,    // 时钟
    input               rst_n,  // 复位信号 (低电平有效)
    input               en,     // 使能信号
    output  reg [3:0]   count_out // 4位计数输出
);

    // always @(posedge clk or negedge rst_n)
    // 敏感列表里多了一个 negedge rst_n
    // 这表示：无论是时钟上升沿，还是复位信号下降沿，都会触发这个模块
    always @(posedge clk or negedge rst_n) begin
        // 复位逻辑，优先级最高
        if (!rst_n) begin
            // 当 rst_n 为0时，强制把计数器清零
            // 这是为了让电路一上电就有个确定的初始状态
            count_out <= 4'b0000;
        end
        // 正常计数逻辑
        else begin
            // 这行代码就完美实现了我们上面的分析：
            // 下一个值 (赋值给count_out) = 当前值 (count_out) + 1
            if (en) begin
                count_out <= count_out + 1'b1;
            end
            //else begin
                //count_out <= count_out; // 自动保持不变
            //end

        end
    end

endmodule