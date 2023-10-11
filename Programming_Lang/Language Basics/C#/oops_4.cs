using System;

public class oops_4
{
	public string color = "red";	//fields

	public static void main()	//methods
	{
		multiArgs(st1: "John", st3: "9/11", st2: "Hello");

		oops_4 obj = new oops_4("White");
		Console.WriteLine(obj.color);
		
		oops_4 obj2 = new oops_4("Black");
		obj2.color = "Green";
		Console.WriteLine(obj2.color);
		Console.WriteLine(obj.color);
	}

	public static void multiArgs(string st1, string st2, string st3)
	{
		Console.WriteLine(st3);
	}

	public oops_4(string st)	//constructor;
	{
		color = st;
		Console.WriteLine("Constructor is invoked");
	}


	/* Access Modifier
	 * public	
	 * private	same class only
	 * protected	inherited or same class
	 * internal
	*/

	private string passcode;

	public string Passcode
	{
		get { return passcode; }
		set { passcode = value; }
	}

    /* shorthand
	 * public string Passcode
	 * {
	 *	get;set;
	 * }
	 * 
	 * get -- read only
	 * set -- write only
	 * increases security
	 */




}

sealed class oops_4_1 : oops_4	//sealed class cannot be inherited. Although it can be accessed by object
{
    public static void main()
    {

        Console.WriteLine("HELOO");
    }
    public oops_4_1(string st1) : base(st1)
    {
        Console.WriteLine("HRloooo");
    }


}


class Animal
{
	public void animals()
	{
        Console.WriteLine("The animal makes a sound");	//overriding
    }
}

class Pig : Animal  // Derived class (child) 
{
    public void animalSound()	//virtual
    {
        Console.WriteLine("The pig says: wee wee");
    }
}

class Dog : Animal  // Derived class (child) 
{
    public void animalSound()	//virtual
    {
        Console.WriteLine("The dog says: bow wow");
    }
}

class Animal1  // Base class (parent) 
{
  public virtual void animalSound()
{
    Console.WriteLine("The animal makes a sound");
}
}

class Pig1 : Animal1  // Derived class (child) 
{
    public override void animalSound()
    {
        Console.WriteLine("The pig says: wee wee");
    }
}

class Dog1 : Animal1  // Derived class (child) 
{
    public override void animalSound()
    {
        Console.WriteLine("The dog says: bow wow");
    }
}


abstract class Animal2	// abstract class object cannot be created // can be inherited and then used
{
    public abstract void animalSound();
    public void sleep()
    {
        Console.WriteLine("Zzz");
    }
}

interface Animal3 //An interface is a completely "abstract class", which can only contain abstract methods and properties (with empty bodies): // no overriding keyword required
{
    void animalSound(); // interface method (does not have a body)
    void run(); // interface method (does not have a body)
}

