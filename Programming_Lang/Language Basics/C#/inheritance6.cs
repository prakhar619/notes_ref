class Shapes{
    public double width;
    public double height;
    public double length;

    //like cpp (unlike java)
    //no access specifier means private
    //access to private: property or change private to protected

    public void showDim()
    {
        Console.WriteLine("Width:"+width+"\tHeight:"+height+"\tlength"+length);
    }
}

class Triangle: Shapes{
    public string style;
    public double Area()
    {
        return width*height/2;
    }

    Triangle(double w,double h,double l,double s)
    {
        width = w;
        height = h;
        length = l;
        style = s;
    }

}

//now T_inherit cannot be inherited (sealed)
sealed class T_inherit: Triangle{
    T_inherit(int w,int h,int l,string s,string i): base(w,h,l,s){
        Console.WriteLine("Base constructor called:");
    }
    //member hiding by subclass result in error in c# 
    //use new keyword for that
    //now to access Triange's style: Triangle.style
    new string style;

}

class vfunction{
    //virtual functions
    //cannot be static or abstract
    //default function present in base class
    public virtual void show()
    {
        Console.WriteLine("WOW");
    }
}
class vvfunction: vfunction{
    //overriding virtual function
    public override void show()
    {
        Console.WriteLine("NOOOOOWOW");
    }

    //use sealed public override show() to prevent futher override
}

abstract class abstract_class
{
    //methods must be implemented by subclass
    //abstract method is automatically virtual, no need to use virtual (error if used together)
    //class containing any abstract function must be declared abstract
    //no objects of abstract class
    public abstract void show();
}

class main{
    //reference variable for one class type cannot normally refer to an object of another class type
    // but a base class datatype variable can refer to derived class object
    // Shapes X = new Triangle(w,h,l,s); NOerror
    // This is like java;



    //Special class called object which is inherited by all classes; even value types are derived from object
    //System.Object is same as object
    //object has its own datamembers
    //  Equals(object obj), Equals(object obj1, object obj2), Finalisze(), GetHashCode(), GetType(), MemberwiseClone(), ReferenceEquals(), ToString()
    //Boxing Unboxing means storing value type in object type; 
}