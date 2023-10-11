//Basics:
/** Unlike other language where programs are directly compiled to assembly lvl lang
Java is compiled by Java compiler(JAVAC) to BYTECODE.
BYTECODE is highly optimised and ready shared(portable).
Then Java Virtual Machine (JVM) present in JRE (Java Runtime Environment) interprets it to assembly lvl lang.
Unlike other compiled code, Java bytecode is machine independent.

JIT (Just in Time) compiler
When JIT is part of JVM some part to code is directly compiled to assembly lvl. Some part is left to 
be interpreted. All this will be finally managed by JVM on interpretation.
*/

import java.io.*;
//Name of main class should match file name;
public class basic_1 {
//Each class should have a main function
    public static void main(String[] args)
    {
        System.out.println("Hello World");
    }
    public static void print_()
    {
    	System.out.print("New ");
        System.out.println("World");
    }
    public static void read_()
    {
	
    }
    public static void condictional_statement()
    {
    	int y = 11;
    	// int y; ref of int data type
    	if(10 > y)
     	y = 10;
     	else if( 11 >= y)
     	y = 12;
     	else
     	y = 13;
     	
     	
     	switch(y)		// y can be string, char, int ,byte, short
     	{
     	case 11:		// duplicate cases are not allowed
     		System.out.println(10);
     		break;
     	default:
     		System.out.println(y);
     	}
     	
    }
    public static void looping_stat()
    {
    	for(int x= 0; x<10; x++)
    	{
    	}
    	
    	for(int x = 20,y = 10;x > y;)
    	{}
    	
    	while( 12 > 11)
    	{
			break;
		}
    	
    	do 
    	{}while(10 > 11);
    	
    }
    
    public static void goto_kindof()
    {
    	first:
    	{
    		second:{
    		third: for(int i = 0; i < 10; i++)
    		{
    		System.out.println("Before Break");
    		if(true) break second;
    		System.out.println("This wont execute");
    		}
    		System.out.println("This wont execute");
    		}
    		System.out.println("This will execute");
    	}
    	
    	outer: for(int i = 0; i< 10; i++)
    	{
    		continue outer;
		}
	}

    public static void new_op()
    {
    	//short circuit logical operators
    	//	|| or 		&& and
    	// Java will not evaluate right hand side when left side is able to predict the value
    	// useful when right depends upon left (dependency)
    	// regular or |   and &
    	
    	int demon = 2, num = 5;
    	if(demon != 0 && num/demon > 10)
    	{}
    	
    }
    
    public static void string_()
    {
    	String str = "Hello world";
    	// not primitive
    	// neither array of char
    	
    	//string are immutable
    	
    	//Methods
    	//	obj1.equals(obj2)
    	//	obj1.length()
    	//	obj1.charAt(int)
    	//	
    }
    public static void casting()
    {
    	//compatible type
    	int x= 123123123;
    	long y= x;
    	double a= 123.123;
    	//incompatible type
	byte z= (byte)x;
	int u=(int)a;		//truncation

/* byte x= 50;
byte y = x * 2;			ERROR because Java uses casting promotion.
Therefore byte on operation automatically becomes int.
Therefore use (byte) casting.

Also d*i	d
     i/d	d
     b*f	f
     and so fore...
     
*/	}


	public static void var_type()
	{
		var avg = 10.0;
		var avgg = 10;
		
		var arr = new int[10];
		
		// wrong way: 	var[] my arr;
		//		var arr[];
		//		var myar = {1,2,3};
		
		//Also wrong:  var avg;		initialisation required
		
		//var connot be used as name of class
		//neither in error catch	    	
	}
}

/* Primitive Data types in java
integer:	byte 8,		short 16,	int 32,		long 64
floating point:		float 32,	double 64
Character:	char 16
Boolean:	boolean
	true         != 1
	false	     != 0

No Unsigned data
 */
 
 /* Literals
 int z = 0b1011
 int x = 05	(base 8; therefore 09 would be error)
 int y = 0x 12  (base 16)
 
 int p = 123__45_5_7; it is valid and percieved as 1234557
 int b = 0b1111_0101_0000_1100
 
 
 
 
 /* Unlike other lang where compiler defines size of each primitive data type
 Java has fixed size for each data type for portability reason
 int 32 bits
 */


 
 
 
 /* Identifiers
 Allowed Name: $test
 Not Allowed: 2count 
 		heig-tem
 		Not/ok
 */
 /*Access Modifier
 Public
 Private
 */

