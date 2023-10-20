
using System;

class className
{
    //classmember: data member, function member
    //type modifier and access specifier for each class member
    public int data_member01;
        //available to all;
    private int data_member02;
        //available only to this class
    internal int data_member03;
        //
    protected int data_member04;
        //

    //data member are also called fields
    //can be instance variable or static variable

    public void function_member(int formal_parameter01)
    {
        //statement;

        this.data_member01 = 20;
        //this is used to refer to class members
    }

    //include methods, constructor, destructor, operators, indexers, events and properties
    
    //no default constructor compulsory;
    public className(): this(0)
    {
        //access specifier on constructor too!

        //this constructor calls className(int x)
            //using :this()
        //also any argument can also be passed
            //className(x,y): this(x)
        
    }
    public className(int x)
    {
        data_member01 = x;
        data_member02 = 0;
        data_member03 = 0;
        data_member04 = 0;
    }

    ~className()
    {
        //destructor is executed when garbage collectors collects the last refering instance obj
        //not like (C,C++) when instance obj is out of scope
        //unknown when it will be executed
        
        //no return type, no argument

        //usually not needed

    }

    static int x;
        //static member cannot be accessed through an object reference
        //must be accessed through its class name
        //static is initialised before its class is used
        //all instances share the same static variable
        //static method does not have this ref
        //static method can directly call other static method or field of its class 
    
    static className()
    {
        x = 20;
    }
        //static contructor used to initialise static data member
        //can never be accessed
    
}

static class stat
{
    //all member be static
    static int static_member_only;
    static int function1(int x)
    {
        return 1;
    }
}
class mayBe_main
{
    static int Main()
    {
        className instance_obj1;                //class declaration is just a type describtion
        instance_obj1 = new className();        //this creates a actual object
        //instance_obj1 is not the actual object; it is just refering to the object
            //kind of like pointer
        //instance_obj1 is object reference variable
            //value during = (assignment) and passed in function is done by call by ref
        
        instance_obj1.data_member01 = 10;

        int x = new x();
        //permitted to use new with the value type


        //Object Initializer
            //initialize public data members
        className obj = new className {data_member01=10};
        return 0;
    }
}