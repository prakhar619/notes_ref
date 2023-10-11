
//OOPs: class   (methods,data)
//	objects 	(diff in class vs objects)
//	polymorphism	(overloading, overriding, interfaces, abstract)


public class struct
{
	int x;
	int y;
}				//object reference is pass by ref in java	(call by reference)
				// primitive datatypes is pass by value		(call by value)

public class oops_3
{
	static int x = 10;			//static object unlike non static retain value; their value change either directly or through object creation 
	int y = 20;				// will result change in all object.x and x
	
						// static object are created during class execution 
						// rather then when object object or classs are created
						
	/* static object can access static object of their class(method or data) directly.
	for non static, object needs to be created.
	they cannot use this or super keyword
	*/
	
	private int z = 30;
	
	oops_3()
	{
		System.out.println("Constructor Initiatiated");
	}
	
	oops_3(int y)	//contructor overloading
	{
	 	this.y = y;	//this refer to global class object
	 }
	
	public void change()
	{
		y = 50;
		x = 30;
	}
	
	
	public void change(int x, int y)		//method overloading
	{
		this.x = 500;
		this.y = 1000;
	}
	
	public void class_asObjects(struct varr)
	{
		x = struct.x;
		y = struct.y;
	}
	
	private void access_private()
	{
		System.out.println("Private Method");	// cannot be accessed outside class or in main
	}
	
	public class inner
	{
		int inner_x;
		int inner_y;
		
		inner()
		{
		System.out.println("Outer class cannot access inner class");
		System.out.println("But inner class can access outer class");
		}
	}
	
	public void varArgs(int ... x)		//try to remove any ambiguity else error
	{
		System.out.println("Variable Length Argument");	// varArgs() or varArgs(1,3,5) or varArgs(5,6,7)
		for(int v : x)			// x.length for geting no of args
		System.out.println(v);
	}
	
	
	
	public static void main(String args[])//cmd line argument		// main should be public because it is called by an outside class
	{
		x = 900;
		oops_3 varr = new oops_3();
		varr.y = 1200;
		varr.x = 200;
		System.out.println("Y value is:"+varr.y);
		System.out.println("X value is:"+varr.x);
		System.out.println("X direct value is:"+x);
	}
}


//Types of access specifiers
//	no specifier
//	public
//	private
//	protected

//INHERITANCE

class superclass{
	int i,j;	//no AS(access specifier)
	
	void supfunction()	//no AS(access specifier)
	{
		System.out.println("i and j are:"+i+" "+j);
	}
	
}

class subclass extends superclass {
	//now we can access superclass without creating object when we create object for subclass
	//also no object creation for using i
	System.out.println("i value is "+i);
	}



//INTERFACES
/* A class implement multiple interface
Interfaces can have data variable using final or static
*/

public interface funStruct
{
	int function_1(int x, int y, int z);
	double function_2(double x, double y, double z);
	
	final int i = 10;
	static int y = 20;
}

public interface_class implements funStruct //client (kind of subclass)	//public interface_class implements funcStruct,funStruct2,funcStruct3
{
	public int function_1(int x,int y,int z)
	{
		System.out.println("Function 1 accessed");
		return x+y+z;
	}
	
	public double function_2(double x, double y,double z)
	{
		System.out.println("Function 2 accessed");
		return x*y*z;
	}
	
	public void function_33()
	{
		System.out.println("function absent in interface");
	}
}

public class main_interface 
{
	void main_in()
	{
	funStruct obj = new interface_class();	// interface_name obj = new client_name;	interface referencing ; cannot access non interface method like function_33;
	interface_class obj1 = new interface_class();	// client_name obj = new client_name;	can access non interface function
	//access function using .
	}
}

		
abstract public main1_interface implement funStruct
{
	//when we dont want to fully implement interface
	
}


// NESTED INTERFACE
//	Interface inside of class or interface itself

class parent
{
	public interface funStructt
	{
		int functionn_1(int x);
		int functionn_2(int y);
	}
}

class client_ implements parent.funStructt
{
	int functionn_1(int x)
	return x*x;
	int functionn_2(int y)
	return -y;
}

class main_interface
{
	void main_in()
	{
		parent.funStructt obj = new client_();
	}
}
		

