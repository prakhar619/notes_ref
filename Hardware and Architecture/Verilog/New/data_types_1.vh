//verilog is case sensitive

integer a;   //variable a

//Operators
y = ~a;     //unary operator
x = y | a;  //binary operator
x = (y>5)?y:a;  //ternary

//Number Format
//[size]'[base_format][number]
    //Base Format
        //Decimal(default)  'd or 'D
        //binary            'b
        //hexdecimal        'h or 'H
        //octal             'o or 'O

//Hexadecimal AbcDEf are case insensitive

a = 3'b101;  //size 3 base 2(binary) number 101
b = 1'hA;  //size 1 base 16(hex) num A
c =  3'd932; //
d =  3'h70; //decimal val 112
e = 2'o76;  //octal

u = 16'b1010_1111_1010_1100;//underscore legal

//unsized
integer a = 424;
integer b = 'h12Ad';

//negative as 2's complement
ne = -6'd3; //-3 stored as 2's complement of 3
//illegal   ne = 6'd-4

String a = "Hello World";//each char 1 byte

//identifier
    //alphanumeric with _ and $
    //case sensitive
    //cannot start with digit or $

//Keyword
    //always
    //and
    //begin
        //and_onnnnnnnnnnnnnnn

//DATATYPE
    //All datatypes(except real and event) can hold any of these 4 values
        //0
        //1
        //x
        //z (high impedance)

//During vector declaration like
    wire[4:0];
    reg [23:-5];
    //msb can be smaller than lsb

    //Nets
        //Wires to connect hardware entities
        //Most popular net:wire
        wire[3:0] bus0;     //4bit wire

    //Variables
        //described like flipflop
        //reg
            //can also store string
            //if reg big or small -> padd " " or truncate
            reg[3:0] d0;
            reg[8*11:1] = "HEllo World";// 11 char -> 11*8 bit
        //Integer
            //general purpose variable
            //32bit wide
        //time
            //unsigned variable
            //64bit wide
        //realtime
            //real/floating point values
        //real
            //floating point variable

//Assign
    d0[1] = 1;
    addr[23:16] = 8'h23;
    
//ARRAY
reg d2[11:0]    //d2 is scalar reg array
                //depth 12
                //1 bit each
reg [0:7] d3[11:0]  //d3 is single dimensional vector net
                    //depth 12
                    //8 bit each
reg [0:7] d4[11:0][3:0]//d4 is 2d array
                        //rows 11:0 therefore 12
                        //col  3:0   therefore 4
                        //8 bit each

d4[0][2] = 8'ha2;

