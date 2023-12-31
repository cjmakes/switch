// Simple mac that blasts 100 byte frames at 100mbps
module mac ( input clk, input crs_dv, input [1:0] rx_data, output tx_en, output reg [1:0] tx_data, input rx_err);

  typedef enum logic [1:0] { PREAMBLE, SFD_1, SFD_2, DATA } state_t;

  logic [1:0] state = PREAMBLE, next_state;
  logic [7:0] count = 8'b0;
  logic [7:0] data = 8'b11001010;

  // State machine logic
  always_ff @(posedge clk) begin
    count = (state == next_state) ? count + 1 : 0;
    state = next_state;
  end

  always_comb
    case (state)
      PREAMBLE: tx_data = 2'b01;
      SFD_1: tx_data = 2'b01;
      SFD_2: tx_data = 2'b11;
      DATA: tx_data = data[ (7-(count*2)) -: 2 ];
    endcase

  // State transition logic
  always_comb
  begin
    case (state)
      PREAMBLE: begin
        // Send 7 octets of preamble
        if (count == 27) begin
          next_state = SFD_1;
        end else begin
          next_state = PREAMBLE;
        end
      end

      // Send 6 bits of SFD
      SFD_1: begin
        if (count == 2) begin
          next_state = SFD_2;
        end else begin
          next_state = SFD_1;
        end
      end

      // Finish SFD
      SFD_2: begin
        next_state = DATA;
      end

      // Send data
      DATA: begin
        if (count == 3) begin
          next_state = PREAMBLE;
        end else begin
          next_state = DATA;
        end
      end
    endcase
    end
endmodule
