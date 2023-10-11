module tb;

reg tb_clk;
reg tb_d;
reg tb_rstn;
reg tb_q;

dff dff0(.clk(tb_clk),.d(tb_d).rstn(tb_rstn),.q(tb_q));

initial begin   
    tb_rstn <= 1'b0;
    tb_clk <= 1'b0;
    tb_d <= 1'b0;
end
endmodule

$time   //means current simulation time
#20     //means advance simulation time by 20 units
$display("Value of a:",a);
$display("String print:%s",string1);
$display("data[start_bit +: width_bit] = 0x%0h",data[8*1 +: 8]);
                                        //%0h for hexa
                                        //%0d for decimal