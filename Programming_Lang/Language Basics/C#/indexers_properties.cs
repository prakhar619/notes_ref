using System;

class indexers{
    //indexers are class members 
    //consists of two functions (accessors functions) :- get, set
    //indexers are used to use instance object with [] like obj[2].

    public int a;
    public int this[int index]{
        get{
            return a*index;
        }
        set{
            //set implicitly receives value
            // obj[index] = value;
            a  = value-index;
        }

    }
}

class maxIndexers{
    //no setter
    int a;
    public int this[double index]
    {
        get{
            return (int)index*a;
        }
    }

    public int this[int index]
    {
        get{
            return (int)index*a;
        }
        set{
            a = value;
        }
    }

    // obj[i,j]
    public int this[int index1, double index2]{
        get{
            return index1*(int)index2*a;
        }
        private set{
            a = (index1-(int)index2)*value;
        }
    }
}

class propertiess{
    //another class member
    //properties do not define storage locations. Instead a property typically manages access to a field.
    //  EXCEPTION: auto-implemented properties 
    // cannot overload properties
    private int prop;
    public int prop_name{
        get{
            return prop;
        }
        set{
            prop = value;
        }
    }

    //creates a storage location automatically
    //variable not directly availiable
    //unlike normal properties cannot be readOnly, writeOnly, (both get;set; required)

    public int autoImp{
        get;set;
    }
}

class main{
    static void Main()
    {
        indexers obj = new indexers();
        obj[3] = 20;
        Console.WriteLine(obj[10]);

        propertiess objP = new propertiess();
        objP.prop_name = 5;
        Console.WriteLine(objP.prop_name);

        objP.autoImp = 10;
        Console.WriteLine(objP.autoImp);
    }
}