#include <iostream>
using namespace std;

//function that can be evaluated both at compile time and run time
    //during compile time run, its argument should be a const value
constexpr int function_cexpr(int c)
{
    return c*c;
}

void reference()
{
    // & means "reference to". Similar to pointer except no need to dereference using * (use directly)
    // & here comes to declaration part like int& x and not  &y(this means you are passing y's address);
    // as reference variable is associated with one value only throughout its life.
    int v[] = {0,1,2,3,4,5,6,7,8,9};
    for(auto&x : v)
    {
        ++x;
    }
    // T a[n] : array of T type and n element 
    // T* p :   pointer to T type data
    // T& a :   reference to T type data
    // T f(A) : function which takes A and returns T data type
}

void ptrs()
{
    int *p = nullptr;
    //nullptr vs NULL(0) . NULL is essentially just zero whereas nullptr is not. Helpful when typeconversion involved.
}

struct Vector{
    int sz;
    double *elem;
};

void vector_init(Vector&v, int s)
{
    v.elem = new double[s]; //new operator allocates memory from an area called free store(also called dynamic memory and heap)
    v.sz = s;
}

class Vector1
{
    public:
        Vector1(int s):elem{new double[s]}, sz{s} {}    //Member initializer list  {}or()
        double& operator[](int i) {return elem[i];}
    private:
        double *elem;
        int sz;
};

// #Member Initializer List
struct S
{
    int n;
    S(int);         //S s1(20)
    S():n(7){}      //S s2;
};

S::S(int x): n{x} {}

int main()
{
    bool b;
    int i;
    char c = 'c';
    double d{12.2};

    i = sizeof(i);
    //Operators:
        // +,-,*,/,%(remainder)
        // ==,!=,<,>,>=,<=

    auto a = 12;
        //with auto = only
        //generic programming
        //initialising also at same time

    //Const and constexpr
        //const means i will not change
        // constexpr means computation at compile time
    const int c_i = 12;
    constexpr double cexpr_d= 1.2*function_cexpr(c_i);

    //ENUM
        //you can remove class from enum class
        //enum class has only assignment, initialization and comparison (== and <) defined;
    enum class colors {red,white,green};
    colors x = colors::red;

}
