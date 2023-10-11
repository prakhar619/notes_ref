//single line comment
/*
module
port
datatypes
module instantiations
behaviour_code
*/

module dff (input d,rstn,clk,output q);
reg q;
always @ (posedge clk) begin    //this code is executed at positive edge of clk
    if(!rstn)
        q<=0;
    else
        q<=d; 
end
endmodule

/*
Design Style
    Top-Down
        top component then its dependency modules, then dependency module dependency and so on.
    Bottom-Up
        basic module then higher lvl module

