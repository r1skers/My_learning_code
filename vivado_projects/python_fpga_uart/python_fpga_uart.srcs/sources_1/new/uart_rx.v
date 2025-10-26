// 模块：UART接收器
// 功能：将串行rxd信号转为8位并行数据data_out
module uart_rx(
    input             clk,        // 系统时钟 (例如 50MHz)
    input             rxd,        // 串口数据输入
    output reg [7:0]  data_out,   // 8位并行数据输出
    output reg        data_valid  // 数据有效脉冲
    );

    // 参数：时钟频率 / 波特率
    // 仿真时，我们会用 50MHz 时钟和 9600 波特率
    // 50,000,000 / 9600 = 5208.33，我们取 5208
    parameter CLKS_PER_BIT = 5208;

    // 状态机状态
    localparam STATE_IDLE = 0;
    localparam STATE_START = 1;
    localparam STATE_DATA = 2;
    localparam STATE_STOP = 3;

    reg [2:0] state = STATE_IDLE;
    
    // 计数器，用于计算 CLKS_PER_BIT
    reg [12:0] clk_counter = 0; // 确保它足够大 (能数到 5208)
    
    // 计数器，用于计算接收了多少位数据 (0到7)
    reg [3:0] bit_counter = 0;
    
    // 寄存器，用于暂存正在接收的数据
    reg [7:0] data_reg = 0;

    // 主逻辑：在每个时钟上升沿触发
    always @(posedge clk) begin
        data_valid <= 0; // 默认情况下，数据无效

        case(state)
            STATE_IDLE: begin
                if(rxd == 0) begin // 检测到起始位 (低电平)
                    state <= STATE_START;
                    clk_counter <= 0; // 重置时钟计数器
                end
            end
            
            STATE_START: begin // 等待半个bit时间，到起始位中间采样
                // CLKS_PER_BIT / 2
                if(clk_counter == (CLKS_PER_BIT / 2)) begin
                    if(rxd == 0) begin // 再次确认是起始位
                        state <= STATE_DATA; // 确认成功，进入数据接收状态
                        clk_counter <= 0; // 重置时钟计数器
                        bit_counter <= 0; // 从第0位开始接收   
                    end else begin
                        state <= STATE_IDLE; // 误判 (毛刺)，返回IDLE
                    end
                end else begin
                    clk_counter <= clk_counter + 1;
                end
            end
            
            STATE_DATA: begin // 接收8位数据
                // 等待一个完整的bit时间
                if(clk_counter == CLKS_PER_BIT - 1) begin
                    clk_counter <= 0;
                    data_reg[bit_counter] <= rxd; // 采集数据 (从 LSB 即第0位开始)
                    
                    if(bit_counter == 7) begin // 8位数据是否都收完了？
                        state <= STATE_STOP; // 是，进入停止位状态
                    end else begin
                        bit_counter <= bit_counter + 1; // 否，准备接收下一位
                    end
                end else begin
                    clk_counter <= clk_counter + 1;
                end
            end
            
            STATE_STOP: begin // 接收停止位
                // 再等待一个完整的bit时间
                if(clk_counter == CLKS_PER_BIT - 1) begin
                    if(rxd == 1) begin // 停止位必须是高电平
                        data_out <= data_reg; // 数据有效，把收到的数据送到输出端口
                        data_valid <= 1; // 同时拉高 data_valid 信号一拍
                    end
                    // 无论停止位是否正确，都返回IDLE，准备接收下一个字节
                    state <= STATE_IDLE; 
                end else begin
                    clk_counter <= clk_counter + 1;
                end
            end
            
            default:
                state <= STATE_IDLE;
        endcase
    end
    
endmodule