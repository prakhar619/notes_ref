//2 new feature added in jdk 5 and jdk 8 respectively; generic and lambda expressions

/*
 * It has 2 component
 *      Lambda expression 
 *      Functional Interface
 * 
 * It makes implementation of functional interface easy
 * 
 * Functional Interface: abstract interface with only one function
 *                      Abstract Interface: Interface with no static,default,private method
 * 
 * Lambda expression itself can be of 2 types
 *      Single Expression 
 *      Block lambda/ expression lambdas
 */

//fuctional interface
interface lamdda
{
    double getValue();
}

interface para_lamda
{
    double get(int k);
}

//generic functional interface
interface genFI<T> {
    T get(T t);
}

//Method Ref (3 ways)

//Method ref with generics

//Construtor ref
interface const_interface{
    void get();
}

public class lamda_exp_15   //interface not implemented
{
    public static void main(String args[])
    {
        lamdda obj; //obj referencing interface
        obj = ()->123.45;   //here obj is intialised and function implemented(without using function name) at same time

        System.out.println("Using the interface obj/method:"+obj.getValue());
        
        para_lamda obj2 = (n)->(n%2);
        //para_lamda obj2 = (int n)->(n%2);
        System.out.println("Parameterised Lambda expr:"+obj2.get(5));
   
        genFI <Integer> obj3 = (n)-> {
            if(n %2 == 0)
            System.out.println("Even");
            else 
            System.out.println("ODD");
            return 1;
        };
        //any local variable of main/function used inside lambda block becomes final
        //therefore its value should not be changed either inside lambda block or outside it. else error


        lamdba_args(obj2,10);
        lamdba_args((n)->(n%2),20); //this will also work
        //now instead of passing interface obj or lambda expr(implementation)
        //we can pass method reference, this method will become the implementation
        lamdba_args(class_ref::method_ref,20);
        //class_ref::static_mth_ref
        //this will work for static method_ref only
        //another method
        // object_ref::method_ref for non static
        //another method
        //make lambda_args as lambda_args(class_name obj,class_name::method_name,...)
            //by passing obj of that class we can access class_ref::mth_ref where mth_ref is instance method

        //super::method_name to refer to method of superclass
        //class_ref::new    constructor can also be given as references
        const_interface obj4 = class_ref::new;

        //instance method means non static method (meaning instance of object)
        //
    }

    public static double lamdba_args(para_lamda l, int s)
    {
        System.out.println("Lambda with args called");
        return l.get(s);
    }

}

class class_ref
{
    class_ref()
    {
        System.out.println("Constructor of class_ref invoked");
    }
    public static double method_ref(int x)
    {
        if(x%2 == 0)
        return 1.0;
        else
        return 0.0;
    }
}

/*
MyArrayCreator<MyC1ass[]> mcArrayCons =  MyC1ass[]::new
MyC1ass[] a = mcArrayCons.func(2);
a[0] = new MyC1ass(1);
a[1] = new MyC1ass(2);
 */


 //there are some predefined functional interface
 //Consumer<T>
 //Supplier<T>
 //Function<T,R>
 //Predicate<T>
 // and more...