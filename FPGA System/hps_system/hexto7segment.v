// www.referencedesigner.com 
// http://referencedesigner.com/tutorials/verilog/verilog_19.php
// Verilog Tutorial
// Hex to 7 Segment Example
  
module hexto7segment(
	input  		[3:0]		in,
	output reg 	[6:0]		out
);

always @*
	case (in)
		4'b0000 :      	//Heinadecimal 0
		out = 7'b0111111;
		4'b0001 :    		//Heinadecimal 1
		out = 7'b0000110  ;
		4'b0010 :  		// Heinadecimal 2
		out = 7'b1011011 ; 
		4'b0011 : 		// Heinadecimal 3
		out = 7'b1001111 ;
		4'b0100 :		// Heinadecimal 4
		out = 7'b1100110 ;
		4'b0101 :		// Heinadecimal 5
		out = 7'b1101101 ;  
		4'b0110 :		// Heinadecimal 6
		out = 7'b1111101 ;
		4'b0111 :		// Heinadecimal 7
		out = 7'b0000111;
		4'b1000 :     		 //Heinadecimal 8
		out = 7'b1111111;
		4'b1001 :    		//Heinadecimal 9
		out = 7'b1101111 ;
		4'b1010 :  		// Heinadecimal A
		out = 7'b1110111 ; 
		4'b1011 : 		// Heinadecimal B
		out = 7'b1111100;
		4'b1100 :		// Heinadecimal C
		out = 7'b0111001 ;
		4'b1101 :		// Heinadecimal D
		out = 7'b1011110 ;
		4'b1110 :		// Heinadecimal E
		out = 7'b1111001 ;
		4'b1111 :		// Heinadecimal F
		out = 7'b1110001 ;
	endcase

endmodule
