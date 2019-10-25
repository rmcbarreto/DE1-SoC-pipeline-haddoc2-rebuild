module mux4x1 (
	input					clk,
	input	[0:8][7:0]	data_in,
	input	[4:0]			sel,
	output reg [7:0]	data_out,
	output reg [4:0]	out_aux
);

	//Always block - the statements inside this block are executed when the given sensitivity list 
	//is satidfied. for example in this case the block is executed when any changes occur in the three signals 
	//named 'Data_in_0','Data_in_1' or 'sel'.
	always @ (posedge clk)
	begin
		if(sel == 0)
		begin
			out_aux = 0;
			data_out = data_in[0];
		end
		else if(sel == 1)
		begin
			out_aux = 1;
			data_out = data_in[1];
		end
		else if(sel == 2)
		begin
			out_aux = 2;
			data_out = data_in[2];
		end
		else if(sel == 3)
		begin
			out_aux = 3;
			data_out = data_in[3];
		end
		else if(sel == 4)
		begin
			out_aux = 4;
			data_out = data_in[4];
		end
		else if(sel == 5)
		begin
			out_aux = 5;
			data_out = data_in[5];
		end
		else if(sel == 6)
		begin
			out_aux = 6;
			data_out = data_in[6];
		end
		else if(sel == 7)
		begin
			out_aux = 7;
			data_out = data_in[7];
		end
		else if(sel == 8)
		begin
			out_aux = 8;
			data_out = data_in[8];
		end
		/*
		else if(sel == 9)
		begin
			out_aux = 9;
			data_out = data_in[9];
		end
		else if(sel == 10)
		begin
			out_aux = 10;
			data_out = data_in[10];
		end
		else if(sel == 11)
		begin
			out_aux = 11;
			data_out = data_in[11];
		end
		else if(sel == 12)
		begin
			out_aux = 12;
			data_out = data_in[12];
		end
		*/

	end
	 
endmodule