//unique_ptr<T>
//  automatic delete the object when no longer needed;
// complex z2 {z1}; means complex z2; z2 = z1; all these are copy and not by ref

//copy and move
class vector1
{
    private:
        double* elem;
        int sz;
    public:
        vector1(int s);                             //Constructor
        ~vector1(){ delete[] elem;}                 //Destructor
        
        vector1(const vector1& a);                  //copy constructor
        vector1& operator=(const vector1& a);       //copy assignment

       // vector1(vector1&& a);                       //move constructor
        vector1& operator=(const vector1&& a);       //move assignment

            /*&& operator
            rvalue reference
            a value that you cant assign to, such as an integer returned by a function call
            rvalue ref is a reference to something that nobody else can assign to*/

        vector1(vector1&& a):elem(a.elem),sz{a.sz}
        {
            a.elem = nullptr;
            a.sz = 0;
        }

        /*
        So this copy constructor is used to copy the vector1 object
        Imagine someone wants to copy the vector1 obj1 then use vector1 obj2(obj1) will give an copied vector1
        But if move constructor is described then move is used over copy.*/        
};

//Templates
    //A template is a class or a function that we parameterize with a set of types or values.'
    //are compile time mechanism, so their use incurs no run time overhead
    //1. Class templates
    //2. Function Templates
template<typename T>
class  vector2
{
    private:
        T* elem;
        int sz;
    public:
        vector2(int s);
        ~vector2(){delete[] elem;}

        T& operator[](int i);
        const T& operator[](int i) const;
        int size() const {return sz;}
};

template<typename T>
vector2 <T>::vector2(int s)
{
    elem = new T[s];
    sz = s;
}

template<typename Container,typename value>
value sum(const Container& c, value v)
{
    for(auto x: c)
    v+=x;
    return v;
        //v is the initial value and acts as accumulator.

}

//Variadic Templates
    //variadics
    //a template can be defined to accept an arbitary no of argument of arbitary types
#include <iostream>
template<typename T, typename... Tail>
void variadic_function(T head,Tail... tail)
{
    std::cout << head <<std::endl;
    variadic_function(tail...);
}
void variadic_function()    //Base case
{}

//Function Objects
    //Functors
    //Define objects that can be called like functions
template<typename T>
class Less_than{
    private:
        const T val;
    public:
        Less_than(const T& v): val{v} {}
        bool operator()(const T&x) const {return x < val;}

};

void functors(int n)
{
    Less_than<int> obj1{42};
    bool b1 = obj1(n);       //true if n < 42
}

//Aliases
using size_t_1 = unsigned int;

template<typename T>
class vector3{
    public:
        using value_type = T;
};
template<typename C>
using element_type = typename C::value_types;
