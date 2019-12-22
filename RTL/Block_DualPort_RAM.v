module Block_DualPort_RAM #(
    parameter ADDR_WIDTH = 16)(
    input clka,
    input clkb,
    input [ADDR_WIDTH-1:0] addrb,
    input [ADDR_WIDTH-1:0] addra,
    input [31:0] dina,
    input wea,
    output reg [31:0] doutb
);

(* ram_style="block" *) reg [31:0] mem [(2**ADDR_WIDTH-1):0];

always@(posedge clka) begin
    if(wea) 
        mem[addra] <= dina;
end

always@(posedge clkb) begin
    doutb   <=  mem[addrb];
end

endmodule