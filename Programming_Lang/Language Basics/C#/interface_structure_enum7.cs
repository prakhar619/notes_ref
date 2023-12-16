//Interface
    //similar to abstract class but no default implementation
    //no body allowed
    //single class, multiple interface
public interface I{
    int GetNext();
    void Reset();
    void SetStart(int x);

    //interface property
        //although it looks like autoimplemented property, its actually not as it needs to be implemented
    int Next{
        get;
        set;
    }

    public int this[int index]{
        get;
        set;
    }
}

class ByTwos : I {
    int start;
    int val;
    public ByTwos() {
        start = 0;
        val = 0;
    }

    public int GetNext(){
        val+=2;
        return val;
    }

    public void Reset(){
        val = start;
    }

    public void SetStart(int x){
        start = x;
        val = start;
    }

    public int Next{
        get{
            val +=2;
            return val;
        }
        set{
            val = value;
        }
    }

    int this[int index]{
        get{
            return val;
        }
        set{
            val = value;
        }
    }
}

public interface II : I{
    public void MethNew();

}

public class CII : II {

    //Explicit interface member implementation or Explicit Implementation.
        //Now you cannot access the methods from the object of class.
            //it must be accessed via interface ref ()
            //this method is not public member of class (private by default)
        //helps in removing ambiguity from two interface same named methods

    //private by default;
    int II.MethNew(){
        return 1;
    }

    public int MethNew(){
        II obj = this;
        return obj.MethNew();
    }
}


public interface name_I{
    public void name_all();
}

//Structure
    //class are ref type;
    //struct are like clas but value type (copy created when = or passed as param)
    //struct cannot inherit other classes or structs
    //can define constructors but not destructors
    //can be created with and without new keyword;
        //without new constructor in not called (obj not initialised).
struct Name : name_I{
    Name[] ar;
    Name(){
        ar = new Name()[10];
    }

    public void name_all(){
        for(int i = 0; i < 10; i++)
        {
            Console.WriteLine(ar[i]);
        }
    }
}

enum Apple{
    Jonathan, GoldenDel, RedDel, Winesap, Cortland, McIntosh
};

//both enum and struct inherit System.ValueType which itself inherit object

