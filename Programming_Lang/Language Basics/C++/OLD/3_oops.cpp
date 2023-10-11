#include <iostream>
#include <string>
using namespace std;

/* Object oriented  programming 
class
object
Pillars of OOPs
    polymorphism
    abstraction
    inheritance
    encapsulation
*/

class class01
{
    private:
        int x ;
    public:
        int y ;
    //defining a contructor
    class01()
    {
            cout << "Obj has been created and this constructor has been executed \n";
    }
    int func ()
    {   
        x = 10;
        return x;
    }
    int function01();

    //defining a destructor
    ~class01()
    {
        cout << "Object has been destroyed and this destructor has been executed \n";
    }
};   // [important semicolon]

// function body outside although head of function need to be inside class
int class01 :: function01()
{
    cout<<x<<"\n";
    return 1;
}




class superclass
{
    int private01 = 10;
    public:
    int public01  = 20;
    protected:
    int protected01  = 30;
};
class subclass_private : private superclass
{public:

};
class subclass_protected : protected superclass
{public:
};
class subclass_public : public superclass
{public:

};

int main()
{
    class superclass ob_superclass;
    class subclass_private ob_superclass_private;
    class subclass_protected ob_superclass_protected;
    class subclass_public ob_superclass_public;

//    cout << ob_superclass.private01 << endl;
//    cout << ob_superclass.protected01 << endl;
    cout << ob_superclass.public01 << endl;

//    cout << ob_superclass_private.private01 << endl;
//    cout << ob_superclass_private.protected01 << endl;
//    cout << ob_superclass_private.public01 << endl;

//    cout << ob_superclass_protected.private01 << endl;
//    cout << ob_superclass_protected.protected01 << endl;
//    cout << ob_superclass_protected.public01 << endl;
    
//    cout << ob_superclass_public.private01 << endl;
//    cout << ob_superclass_public.protected01 << endl;
    cout << ob_superclass_public.public01 << endl;


   class01 obj;
    obj.y = 10;
    int r =  obj.func();
    int m = obj.y;
    cout << r << "\n";
    obj.function01();
}
