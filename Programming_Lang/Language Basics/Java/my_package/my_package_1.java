package my_package;        //my_package name should be same as directory name
// if unspecified default package name = class name

// different classes in same file is eqv to two classes in two different file
// Deal everything in classes

// public 	(everywhere)
// private 	(only within same class)
// no access specifier 	(same package full access(subclass or not)	//more private than protected
// protected	(same class, all subclasses (same package, different package), same package(non subclasses)

/*
Package
	subPackage
		class
			subclass
			subclass
		class
	class
	class
	
	
Package
	subPackage
		sub_subPackage
			class
			class
		class
	class
	class
	class
*/

//Directory name should be same as package name exactly

/*JavaRunTime use 1.)Current Dir
 * 				2.)Specify directory path by setting CLASSPATH environment variable
 * 				3.) use -classpath with java and javac to specify path
 * **while mentioning path, specify the directory in which package dir is present
 * like C:/usr/Home and not C:/usr/Home/mypack
 */

 //Java needs atleast one static function inside package to execute the whole package. 
 //That static function is then treated as main
	
public class my_package_1
{
	protected int x = 10;
	public my_package_1()		//constructor needs to be public
	{
		System.out.println("My_package_1 accessed");
	}

	public static void functi(int x)
	{
		System.out.println("My_Package_1 member function(Functi) accessed");
	}

	public void opera(int y)
	{
		System.out.println("My_package_1 member function(Opera) accessed");
	}

}
