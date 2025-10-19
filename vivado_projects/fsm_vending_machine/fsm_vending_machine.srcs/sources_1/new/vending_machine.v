module vending_machine (
    input clk,
    input rst,
    input coin_in,
    input select,
    output reg dispense
);

parameter IDLE     = 2'b00;
parameter COIN     = 2'b01;
parameter DELIVERY = 2'b10;

reg [1:0]current_state;
reg [1:0]next_state;

always @(posedge clk or posedge rst) begin
    if (rst)begin
        current_state <= IDLE;
    end else begin
        current_state <= next_state;
    end
end

always @(*) begin
    case (current_state)
        IDLE:begin
            if(coin_in) next_state = COIN;
            else next_state = IDLE;
        end
        COIN:begin
            if(select) next_state = DELIVERY;
            else next_state = COIN;
        end
        DELIVERY:begin
            next_state = IDLE;
        end
        default: next_state = IDLE;
    endcase
end  

always @(*) begin
    case(current_state)
        IDLE: dispense = 1'b0;
        COIN: dispense = 1'b0;
        DELIVERY: dispense = 1'b1;
        default: dispense = 1'b0;
    endcase
end
endmodule