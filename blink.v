module blink (
    input      clk_i,
    output reg led_o
);
localparam MAX = 5_000_000;
localparam WIDTH = $clog2(MAX);

reg  [WIDTH-1:0] count;

always @(posedge clk_i) begin
	count = count + 1'B1;
	led_o <= count[WIDTH-1:WIDTH-2];
end
endmodule
