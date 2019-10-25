module readOCM(
	input						clk, reset,
	input						start,
	output reg				finish,

	// On-Chip RAM 0 s2 (read)
	input			[ 7: 0]	ocm0_readdata,
	output reg	[16: 0]	ocm0_addr,
	output reg				ocm0_chip,
	output reg				ocm0_clk_enab,
	
	// Output Haddoc
	output reg	[ 7: 0]	data_out,
	output reg				enable,
	output reg				in_dv
);

	// Declare state register
	reg [ 2: 0]	state;
	
	// Declare states
	parameter S0 = 0, S1 = 1, S2 = 2, S3 = 3, S4 = 4;
	
	reg [16: 0]	addr = 0;

	reg [15: 0]	output_counter = 0;
	
	// Output depends only on the state
	//always @ (state) begin	// Every time the state changes, it executes only one time
	always @ (posedge clk) begin
		case (state)
			S0:
				begin
					addr = 0;
					
					ocm0_clk_enab = 0;
					
					in_dv = 0;
				end
			S1:
				begin
					enable = 0;
					finish = 0;
					output_counter = 0;
					
					ocm0_addr = addr;
					ocm0_chip = 1;
					ocm0_clk_enab = 1;
					
					addr = addr + 1;
				end
			S2:
				begin
					ocm0_addr = addr;
					ocm0_chip = 1;
					ocm0_clk_enab = 1;
					
					addr = addr + 1;
				end
			S3:
				begin
					ocm0_addr = addr;
					ocm0_chip = 1;
					ocm0_clk_enab = 1;
					
					data_out = ocm0_readdata;
					
					enable = 1;
					in_dv = 1;
					
					addr = addr + 1;
					
					output_counter <= output_counter + 1;
				end
			S4:
				begin
					finish = 1;
					
					ocm0_clk_enab = 0;
					
					in_dv = 0;
				end
			default:
				begin
					addr = 0;
					output_counter = 0;
					finish = 0;
					
					ocm0_clk_enab = 0;
					
					enable = 0;
					in_dv = 0;
				end
		endcase
	end

	// Determine the next state
	always @ (posedge clk or posedge reset) begin
		if (reset)
			begin
				state <= S0;
			end
		else
			case (state)
				S0:
					if(start)
						state <= S1;
				S1:
					state <= S2;
				S2:
					state <= S3;
				S3:
					begin
						if(addr >= 784) // Image size (number of pixels)
							state <= S4;

					end
				S4:
					if(start == 0)
						state <= S0;

			endcase
	end

endmodule

