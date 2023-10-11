package my_package;
//Interface abstracts class by telling what it should do and not how it should do

//Each class that uses interface must implement all of its method
//Default implementation also available
//Static,private method allowed

//Variables inside interface are final and static and must be initialised
//All methods and variables are public

//interface itself can be public, unspecified, abstract, final   //protected not allowed
public interface interface_7    //same name as the file (class)
{                               //access: unspecified(same package access),public(all access),
    int sum(int x,int y,int z);
    int mult(int x,int y,int z);
    int div(int x,int y);
}

//Interface can also be member of class or another interface

//can be public;  BUT IN JAVA 1 FILE ONE PUBLIC CLASS
class nested_interface {
    public interface interface_nested
    {
        boolean corr_incorr(int x,int y);
    }
}
//interface can be extended by interface
//these are final variables // constant //cannot be changed
interface var_interface extends interface_7{
    double pi = 3.1415;
    double e = 2.17;
    double g = 10e-20;
    int prime = 3;
}
/*
the defining difference between an interface and a class is that a class can maintain state
information, but an interface cannot.
*/
interface default_intiface
{
    //default implemened methods are optional to implement
    default String getString(String x)
    {
        return x;
    }

    //static method need no object to be called
    // interfaceName.methodName
    static int stat(int x,int y)
    {return x+y;}

    //private method
    private int pri(int x,int y)
    {
        return x+y;
    }

    
}