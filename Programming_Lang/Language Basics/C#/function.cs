using System;
class functions
{
    public void function_(ref int x)
    {
        x = 20;
    }

    public void function__(out int y)
    {
        y = 240;
    }

    public void varArgs(params int[] ar)
    {
        //ar can have zero value also; be carefull
        //use multiple args as array of argument
    }

    public void default1(int x,int y =20,int z =30)
    {
        //once y default, z should also default
        //all default parameter to the right of normal parameter
    }

    public static int Main(string[] args)
    {
        //command line argument for args

        int x = 10;
        functions obj = new functions();
        obj.function_(ref x);
            //use keyword ref to pass value type by ref 
            //x need to be initialised
    

        int y;
        obj.function__(out y);
            //same as ref
            //y needs not be initialised

        //ref vs out ; ref used to pass info as well as return info; out only returns info
        //also pass ref and out of reference variable; its like pointer to a pointer to an object
        
        obj.varArgs(10);
        obj.varArgs();
        obj.varArgs(1,2,3,4);

        obj.default1(10,z:600,y:30);
            //named argument
        return 0;
    }
}