#include <iostream>
using namespace std;

//polymorphism example

template <typename T> class sample
{
    T* ptr;
    T value;
    void print();

};
template <typename T> void sample<T> :: print()
{

}

template <typename U> U sampleFunction(U x, U y)    //template <class U> U sampleFunction(Ux, Uy)
{
    return (x > y) ? x:y;
}

template<typename U,typename X= int > void funn(U x, U y , X z)
{
    U p = 10;
}

//types of template parameter
//	type template parameter
//	non type template parameter
//	template template parameter

template<int b> void functio(int k)
{

}

int main()
{

}
