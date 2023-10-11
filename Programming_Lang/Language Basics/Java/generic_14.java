//data type on which they operate can be passed as arg
// generic class or generic method
// "type safety feature"

//generic similar to c++ template but fundamentally different

//Object: superclass of all classes
//          gives us ability to create classes, interfaces and methods

//Generics work only with reference types
//      therefore no primitive datatype (use type wrapper)
public class generic_14 {
    public static void main(String args[])
    {
    gen<Integer> iob = new gen<Integer>(88);    //autoboxing
    // iob = new gen<Double>(3.3); will give error during compiler time
    Integer m = iob.print();

    //raw code for legacy support
        // gen iob2 = new gen<Integer>(double.valueof(88)); raw type
        // but cast before explicit if object returned like
            //Integer m = (Integer) iob2.print();   where print return T type object

    //modern declaration
        //gen<Integer> iob = new gen<>(88);

    nongen iob_new = new nongen(22);
    Object m_new = iob_new.print();
    Integer k = (Integer) m_new;    //explicit cast to retrieve data
        //invalid cast like string to int will compile but error during runtime
   
    Integer ar[] = {1,2,3,4,5,6};
    genMethod.genMeth(ar[1], ar);
   
    }
}

// T is type parameter
// convention to use T as name of datatype
// V and E also used
// var cannot be used
class gen<T> {
    T ob;   //ob is of data type T
    gen(T o)    //o arg is of data type T
    {
        ob = o;
    }

    public T print()
    {
        System.out.println("Object is:"+ob);
        System.out.println("Object features:"+ob.getClass().getName());
        return ob;
    }


}
// class_name <type_arg_list> var_name= new class_name<type_arg_list>(cons_arg_list); to declare obj of class
class gen2<T,V> {
    T ob;
    V obj;
}

// to limit what data type T can be; T can now only be double,float,int
//Boundedness feature to prevent type conversion error
// <T extends superclass>
class gen3<T extends Number>{
    T[] ar;
    int avg;
}
//<T super subclass1> means all superclasses of subclass1 are allowed

// one class and one or more interface
// interface datatype variable must be object of class who implement that interface
//class gen3_mod<T extends T_class & T1_interface & T2_interface>{





class gen_wild<T>
{
    T ar[];

    public double avg()
    {
        return 1.0;
    }

    public boolean compareAvg( gen_wild<T> ob)//problem is arg
    {
        if(avg() == ob.avg())
        return true;
        else return false;
    }
    //problem is that gen_wild<T> should be same type as invoking class
    // therefore gen_wild<Integer> cannot take gen_wild<Double> because T already Integer

    public boolean compareAvg_corr(gen_wild<?> ob)
    {
                if(avg() == ob.avg())
        return true;
        else return false;
    }
    // ? wild card ; meaning now argument can be anything is terms of gen_wild obj

    public boolean compareAvg_corr_bounded(gen_wild<? extends Number> ob)//instead of Number any Class with data struct
    {
        return true;
    }
    //int,double,float    and 2dvector,3dvector,4dvector may need wildcard and boundedness at same time

}

class nongen{
    Object ob;
    nongen(Object o)
    {
        ob = o;
    }
    
    public Object print()
    {
        System.out.println("Object is:"+ob);
        System.out.println("Object features:"+ob.getClass().getName());
        return ob;
    }
}




//GENERIC METHOD and GENERIC CONSTRUCTOR

//generic method inside nongeneric class
// generic constructor of nongeneric class

class genMethod
{
   <T> genMethod()
   {

   }
    static <T extends Number, V> boolean genMeth (T n,V[] m)
    {
        System.out.println("GENMethod executed");
       return true ;
    }
    //type parameter declared before return type


}


//GENERIC INTERFACES

interface min<T> 
{
    T min();
    T max();
}


//generic class heirarchy for inheritance


//LIMITATIONS

//1. type parameter cannot be instantiated

/*
 * class gen<T>
 * {
 *  T ob;
 *  gen()
 *  {
 *      ob = new T();   //illegal or wrong
 *  }
 * void function()
 * {
 *  gen<Integer> iob = new gen<Integer>(40,n);  //wrong
 * }
 * }
 */

 //2. static variables/methods cant be generic datatype
 /*
  * class gen<T>
  {
    static T ob;    //wrong
    static T getob()    //wrong
    {

    }
    Although use can declare static  generic method
  }
  */
