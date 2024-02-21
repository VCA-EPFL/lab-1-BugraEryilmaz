//
// Generated by Bluespec Compiler, version 2023.07-33-g1c27a41e (build 1c27a41e)
//
// On Wed Feb 21 20:20:07 CET 2024
//
//
// Ports:
// Name                         I/O  size props
// CLK                            I     1 clock
// RST_N                          I     1 reset
//
// No combinational paths from inputs to outputs
//
//

`ifdef BSV_ASSIGNMENT_DELAY
`else
  `define BSV_ASSIGNMENT_DELAY
`endif

`ifdef BSV_POSITIVE_RESET
  `define BSV_RESET_VALUE 1'b1
  `define BSV_RESET_EDGE posedge
`else
  `define BSV_RESET_VALUE 1'b0
  `define BSV_RESET_EDGE negedge
`endif

module mkTest(CLK,
	      RST_N);
  input  CLK;
  input  RST_N;

  // register going
  reg going;
  wire going$D_IN, going$EN;

  // register shft
  reg [3 : 0] shft;
  wire [3 : 0] shft$D_IN;
  wire shft$EN;

  // register going
  assign going$D_IN = 1'd1 ;
  assign going$EN = !going ;

  // register shft
  assign shft$D_IN = 4'h0 ;
  assign shft$EN = 1'b0 ;

  // handling of inlined registers

  always@(posedge CLK)
  begin
    if (RST_N == `BSV_RESET_VALUE)
      begin
        going <= `BSV_ASSIGNMENT_DELAY 1'd0;
	shft <= `BSV_ASSIGNMENT_DELAY 4'd2;
      end
    else
      begin
        if (going$EN) going <= `BSV_ASSIGNMENT_DELAY going$D_IN;
	if (shft$EN) shft <= `BSV_ASSIGNMENT_DELAY shft$D_IN;
      end
  end

  // synopsys translate_off
  `ifdef BSV_NO_INITIAL_BLOCKS
  `else // not BSV_NO_INITIAL_BLOCKS
  initial
  begin
    going = 1'h0;
    shft = 4'hA;
  end
  `endif // BSV_NO_INITIAL_BLOCKS
  // synopsys translate_on

  // handling of system tasks

  // synopsys translate_off
  always@(negedge CLK)
  begin
    #0;
    if (RST_N != `BSV_RESET_VALUE)
      if (!going)
	$display(shft[3] ?
		   (shft[2] ?
		      (shft[1] ?
			 (shft[0] ?
			    256'h000E000D000C000B000A0009000800070006000500040003000200010000000F :
			    256'h000D000C000B000A0009000800070006000500040003000200010000000F000E) :
			 (shft[0] ?
			    256'h000C000B000A0009000800070006000500040003000200010000000F000E000D :
			    256'h000B000A0009000800070006000500040003000200010000000F000E000D000C)) :
		      (shft[1] ?
			 (shft[0] ?
			    256'h000A0009000800070006000500040003000200010000000F000E000D000C000B :
			    256'h0009000800070006000500040003000200010000000F000E000D000C000B000A) :
			 (shft[0] ?
			    256'h000800070006000500040003000200010000000F000E000D000C000B000A0009 :
			    256'h00070006000500040003000200010000000F000E000D000C000B000A00090008))) :
		   (shft[2] ?
		      (shft[1] ?
			 (shft[0] ?
			    256'h0006000500040003000200010000000F000E000D000C000B000A000900080007 :
			    256'h000500040003000200010000000F000E000D000C000B000A0009000800070006) :
			 (shft[0] ?
			    256'h00040003000200010000000F000E000D000C000B000A00090008000700060005 :
			    256'h0003000200010000000F000E000D000C000B000A000900080007000600050004)) :
		      (shft[1] ?
			 (shft[0] ?
			    256'h000200010000000F000E000D000C000B000A0009000800070006000500040003 :
			    256'h00010000000F000E000D000C000B000A00090008000700060005000400030002) :
			 (shft[0] ?
			    256'h0000000F000E000D000C000B000A000900080007000600050004000300020001 :
			    256'h000F000E000D000C000B000A0009000800070006000500040003000200010000))));
  end
  // synopsys translate_on
endmodule  // mkTest
