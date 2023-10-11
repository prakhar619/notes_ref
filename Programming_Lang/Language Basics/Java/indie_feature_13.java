public class indie_feature_13 {
    public static void main(String args[])
    {
        instance_of.instances();
        extra_features.assertion_used(1);
    }
}

class A
{
    int i,j;
}

class B extends A
{
    int i,j;
}

class C extends A
{
    int k;
}

class D extends A
{
    int k;
}

class instance_of{
    public static void instances()
    {
        A a = new A();
        B b = new B();
        C c = new C();
        D d = new D();

        // instanceof is like this variable is object of which class and rather not datatype of this object
        if( a instanceof A)
        System.out.println("a is instance of A");
        if( c instanceof A)
        System.out.println("c can be cast into A");
        if( a instanceof C)
        System.out.println("a can be cast into C");
        System.out.println();
        A obj;
        obj = d; //A referencing d
        System.out.println("obj now reference to d");
        obj = c;
        if(obj instanceof D)
        System.out.println("obj still can be cast to d");

    }
}


//strictfp class myclass    //for strict and accurate floating point calci


//transient and volatile

class extra_features
{
    extra_features(int n)
    {
        this((double)n);//overhead and slow to use this
    }
    extra_features(double m)
    {
        System.out.println("To refer one constructor to another during constructor overloading");
    }




    //We can call executable file(.exe, .out) from java program
    // Java Native Interface (JNI)
    public native int meth();
    //write native method to link and execute .out file

    //skippppppppinggggggggg


    //Assert keyword
        //assert <condiction> or assert <condition>: <expr> ;
        // is assert true then nothing else AssertionError and expr is thrown into AssertionError constructor
        // also use -ea to enable assertion during runtime
            // java -ea indie_feature_13
        // released and final code is assertion disabled; used just to debug and dev
        // disable assertion using -da option in a specific class
            // -ea:extra_features
    public static void assertion_used(int n)
    {
        assert n > 10;
        //assert n > 10: "n is smaller than 10";
    }
    


}