//2 smart pointers
//1. unique_ptr         (represents unique ownership)
//2. shared_ptr         (represents shared ownership)

#include<memory>
using namespace std;
class X
{
    public:
    int x;
    double y;
    int* n;
};

void f(int i,double y)
{
    X obj;
    X* p = new X;
    unique_ptr<X> sp (new X);

    delete p;
}
/*
unique_ptr:p needs to be deleted whereas obj and sp are automatically destroyed when scope is over
shared_ptr: same as unique_ptr but share ownership and that object is destroyed when the last of its shared_ptrs is destroyed.
*/

//Threads
#include <thread>
#include <iostream>
void thread_func0()
{
    cout << "Thread_func0" << endl;
}
void thread_func1(int x)
{
    cout << "Thread_func1" << endl;
}
struct thread_func2
{
    void operator()()
    {
        cout << "Thread_func2" << endl;
    }
};
struct thread_func3
{
    thread_func3(int x)
    {
        cout << "Thread_func3 constructor" << endl;
    }
    void operator()()
    {
        cout << "Thread_func3" << endl;
    }
};

int main()
{
    thread t0(thread_func0);
    thread t1{thread_func1,10};
    thread t2{thread_func2()};        
    //thread t2(thread_func2());// give error-------------------------------------------------------idk why
    thread t3{thread_func3{30}}; //----------------------why no need to specify () operator--------idk why
    t0.join();
    t1.join();
    t2.join();
    t3.join();
}
