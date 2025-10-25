// 模块：指令解析器
// 功能：解析收到的字节，查找 "ON" 和 "OFF"
module command_parser(
    input             clk,
    input             rst,        // 复位信号
    input      [7:0]  data_in,    // 来自UART的数据 (例如 8'h4F)
    input             data_valid, // 数据有效脉冲
    output reg        led_out     // LED输出
    );

    // 定义 "ON" 和 "OFF" 对应的 ASCII 码
    localparam ASCII_O = 8'h4F;
    localparam ASCII_N = 8'h4E;
    localparam ASCII_F = 8'h46;
    
    // 定义状态机
    localparam STATE_IDLE = 0;   // 0: 空闲，等待 'O'
    localparam STATE_GOT_O = 1;  // 1: 收到了 'O', 等待 'N' 或 'F'
    localparam STATE_GOT_OF = 2; // 2: 收到了 "OF", 等待第二个 'F'

    reg [1:0] state = STATE_IDLE;

    // 主逻辑：在每个时钟上升沿触发
    always @(posedge clk) begin
        if(rst) begin
            led_out <= 0; // 复位时，LED熄灭
            state <= STATE_IDLE; // 回到空闲状态
        
        // 关键：只在 data_valid 为高电平 (即收到一个新字节) 时才处理
        end else if (data_valid) begin 
            case(state)
                STATE_IDLE: begin
                    if (data_in == ASCII_O) begin
                        state <= STATE_GOT_O; // 收到 'O', 进入下一状态
                    end
                    // 收到其他任何字符，都保持在 IDLE 状态
                end
                
                STATE_GOT_O: begin
                    if (data_in == ASCII_N) begin // 匹配到 "ON"
                        led_out <= 1; // 点亮LED
                        state <= STATE_IDLE; // 返回空闲
                    end else if (data_in == ASCII_F) begin // 可能是 "OFF"
                        state <= STATE_GOT_OF; // 进入 "OF" 状态
                    end else if (data_in == ASCII_O) begin // 连续收到 "OO"
                        state <= STATE_GOT_O; // 保持此状态，等待 "O" 后面的 "N"
                    end else begin
                        state <= STATE_IDLE; // 收到 "OX" (X是无效字符)，返回空闲
                    end
                end
                
                STATE_GOT_OF: begin
                    if (data_in == ASCII_F) begin // 匹配到 "OFF"
                        led_out <= 0; // 关闭LED
                        state <= STATE_IDLE; // 返回空闲
                    end else if (data_in == ASCII_O) begin // 匹配到 "OFO"
                        state <= STATE_GOT_O; // 这等同于收到了一个新的 'O'
                    end else begin
                        state <= STATE_IDLE; // 收到 "OFX" (X是无效字符)，返回空闲
                    end
                end
                
                default:
                    state <= STATE_IDLE;
            endcase
        end
    end
    
endmodule