module writeAuxDataOCM(
	input						clk, reset,
	input						in_dv,
	input						out_dv,
	input [0:9][7:0]		out_data_aux,

	// On-Chip RAM 1 s1 (write)
	output reg	[ 7: 0]	ocm1_writedata,
	output reg	[16: 0]	ocm1_addr,
	output reg				ocm1_chip,
	output reg				ocm1_clk_enab,
	output reg				ocm1_write,
	
	output reg 	[15: 0]	count
);

	// Declare state register
	reg [ 2: 0]	state;
	
	// Declare states
	parameter S0 = 0, S1 = 1, S2 = 2, S3 = 3, S4 = 4, S5 = 5;
	
	reg [16: 0] addr_write = 0;
	
	reg [15:0][0:9][7:0] out_values;
	
	reg [5:0] count_num_pixels = 0;
	
	//integer ii = 0;
	
	reg [3:0] num_output = 0;
	reg [4:0] num_pixels = 0;
	
	always @ (posedge clk) begin
		case (state)
			S0:	// reset
				begin
					addr_write = 0;
					
					ocm1_chip = 1;
					ocm1_clk_enab = 1;
					ocm1_write = 1;
					
					num_pixels = 0;
					num_output = 0;
					count_num_pixels = 0;
					
					count = 0;
				end
			S1:	// reset (clean memory)
				begin
					ocm1_writedata = 0;
					ocm1_addr = addr_write;
					addr_write = addr_write + 1;
				end
			S2:
				begin
					addr_write = 0;
				end
			S3:
				begin
					if(out_dv == 1)
					begin
							
						out_values[count_num_pixels] = out_data_aux;
						
						count_num_pixels = count_num_pixels + 1;
						
					end
				end
			S4:
				begin
					if(num_output < 10)
					begin
						if(num_pixels < count_num_pixels)
						begin
							ocm1_chip = 1;
						
							ocm1_clk_enab = 1;
							ocm1_write = 1;
							ocm1_writedata = out_values[num_pixels][num_output];
							ocm1_addr = addr_write;
						
							addr_write = addr_write + 1;
							num_pixels = num_pixels + 1;
							
							count = count + 1;
						end
						else
						begin
							num_pixels = 0;
							num_output = num_output + 1;
						end
					end
				end
			default:
				begin
					ocm1_clk_enab = 0;
					ocm1_write = 0;
					addr_write = 0;
					
					num_pixels = 0;
					num_output = 0;
					count_num_pixels = 0;
					
					count = 0;
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
					state <= S1;
				S1:
					if(addr_write > 4000)
						state <= S2;
				S2:
					state <= S3;
				S3:
					if(count_num_pixels == 15)
						state <= S4;


			endcase
	end

endmodule

