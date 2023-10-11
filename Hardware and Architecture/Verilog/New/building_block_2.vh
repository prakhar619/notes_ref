module name (input port1, [3:0] port2, output port3,inout port4); //default port wire
//variable
//architecture
endmodule;



module porttt(input wire signed a,b,output c);
//default unsigned
endmodule;  


//port connection
    //ordered list
    //.<port_name>(<port>)

module porttt_used(input x,y,output z);
porttt obj0 (x,y,z);
porttt obj1 (.a(x),.b(y),.c(z));
porttt obj2 (.a(x),.b(),.c(z)); //floating port //default value of floating port z (high impedence)
endmodule;

//input port wire
//output port (if store value) reg
//input and inout cannot be reg