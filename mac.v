// Simple mac that blasts 100 byte frames at 100mbps
module mac (
	input clk,
	input crs_dv,
	input [1:0] rx_data,
	output tx_en,
	output [1:0] tx_data,
	input rx_err
);

  // Define state enum
  typedef enum logic [1:0] { PREAMBLE, SFD_1, SFD_2, DATA } state_t;

  // State register
  logic [1:0] state, next_state;
  logic [7:0] count = 8'b0;

  logic [7:0] data = 8'b00110011;
  logic [1:0] tx_reg;

  assign tx_en = 1'b1;
  assign tx_data = tx_reg;

  initial begin
  state = 2'b00;
  tx_reg = 2'b00;
  end

  // State machine logic
  always_ff @(posedge clk) state <= next_state;

  // State transition logic
  always @(posedge clk)
  begin
    case (state)
      PREAMBLE: begin
        tx_reg = 2'b01;

        // Send 7 octets of preamble
        if (count == 56) begin
          next_state = SFD_1;
          count = 0;
        end else begin
          next_state = PREAMBLE;
          count = count + 1;
        end
      end

      // Send 6 bits of SFD
      SFD_1: begin
        tx_reg = 2'b01;

        if (count == 6) begin
          next_state = SFD_2;
          count = 0;
        end else begin
          next_state = SFD_1;
          count = count + 1;
        end
      end

      // Finish SFD
      SFD_2: begin
        tx_reg = 2'b11;
        next_state = DATA;
        count = 0;
      end

      // Send data
      DATA: begin
        tx_reg = data[ (count*2) +: 2 ];

        if (count == 4) begin
          next_state = PREAMBLE;
          count = 0;
        end else begin
          next_state = DATA;
          count = count + 1;
        end
      end

      default: begin
          count = 0;
          next_state = PREAMBLE;
      end

    endcase
    end
endmodule
