// Inheritance box

/*
1. Java doesnt support multiple inheritance
2. But we can implement multiple interface on same class using commas
*/
interface I 
{
	public void function1();
	public void function2();
}

abstract class box implements I 	//superclass	
{
	private double width;
	private double height;
	private double depth;
	
	box(box x)
	{
		width = x.width;
		height= x.height;
		depth= x.depth;
	}
	
	box(double w, double h, double d)
	{
		width = w;
		height = h;
		depth = d;
	}
	
	box()
	{
		width= -1;height= -1;depth = -1;
	}
	
	box(double c)		//cube
	{
		width = c; height = c; depth =c;
	}
	
	double volumn()
	{
		return width*height*depth;
	}
	
	//abstract data type
	// when you want the structure in superclass but functionality(different fucntionality) in subclasses
	abstract double area();		//add abstract keyword in class name declaration also
	
	public void function1()
	{
		System.out.println("OSSS");
	}
}

class boxWeight   extends box {		//extended to include weight
	double weight;
	boxWeight(double w,double h,double d,double m)
	{
	 /*width = w;
	 height = h;
	 depth = d;
	 */
	 super(w,h,d);	//super keyword calls constructor of just above superclass	// super should be in first line of constructor
	 weight = m;
	 }
	 
	 boxWeight(boxWeight x)
	 {
	 	super(x); 		//we are passing boxWeight object instead of box object; still works; box constructor has idea of only its own members
	 	weight = x.weight;	
	 }
	 
	 boxWeight()
	{
		super();
		weight = -1;
	}
	
	//super can also we used to refer members of superclass like "this" keyword
	
	
	double area()
	{
		return volumn()/weight;
	}

	public void function2()
	{
		System.out.println("FUNCTION2");
	}
}
	 
class inheritance_4
{
	public static void main(String[] args)
	{
	boxWeight  box1  = new boxWeight( 10, 20, 30 ,40);
	boxWeight box2 =  new boxWeight( 100, 200, 300 ,400);
	
	double vol1 = box1.volumn();
	double vol2 = box2.volumn();
	
	boxWeight box3 = new boxWeight( box1 );
	double vol3 = box3.volumn();
	
	System.out.println("Volumn of box 1,2 and 3 are:"+vol1+" "+vol2+" "+vol3);
	}
	
	/* order of execution of constructor
		superclass lvl 1	A
		superclass lvl 2	B
		subclass lvl   3	C
		
	Ans: A->B->C	(indiff to super is used or not)
	*/	
		
		
	/* Name conflict
	1. Use super
	2. Method Overriding; A and B both have member with same name. B object created; B member will be accessed
	3. Use final keyword to prevent overridding 
	*/
	
	/* Superclass variable can reference a subclass object like
	A obj_ref;
	B obj = new B();		// class B extends A
	obj_ref = obj;
	obj_ref.A_function();
	*/
	
	/* Dynamic Method Dispatch
	In above example, if A_function overwriting; then B funtion will be executed
	Which function to be executed decided during runtime and not compile time.
	*/
}

class object_class
{
	//OBJECT is a superclass of all java classes;OBJECT can refer to any object of any class;
	//Array in java are implemented as class;
	
	/*
	public final class getClass()
	public int hashCode()
	public boolean equals(Object obj)
	protected Object clone() throws CloneNotSupportedException
	public String toString()
	public final void notify()
	public final void notifyAll()
	public final void wait(long timeout) throws interruptedException
	public final void wait(long timeout, int nanos) throws interruptedException
	public final void wait() throws interruptedException
	protected void finalize() throws Throwable
	*/
	
}

	
