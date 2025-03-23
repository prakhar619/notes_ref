#include <mutex>
#include <thread>
#include <iostream>
using namespace std;
//MUTEX
    //mutual exclusion object

mutex m;
int sh;
void f(int x)
{
    unique_lock<mutex> lck {m};
    //unique_lock constructor acquires the mutex throught m.lock()
    //once the thread is over unique_lock destructor releases the mutex through m.unlock()
    sh+=7;
    cout << "sh updated:" << x << endl;
}
int simple_main1()
{
    sh = 0;
    thread m1{f,1};
    thread m2{f,2};
    m1.join();
    m2.join();
    return 1;
}

mutex m1,m2,m3;
void f2(int x)
{
    unique_lock<mutex> lck1 {m1,defer_lock};
    //defer_lock: dont yet try to acquire the mutex
        //prevents deadlock
    unique_lock<mutex> lck2 {m2,defer_lock};
    unique_lock<mutex> lck3 {m3,defer_lock};
    lock(lck1,lck2,lck3);
    //proceed after acquiring all its mutex arguments and will never block while holding a mutex
    sh+=7;
    cout << "sh updated:" << x << endl;
}

int simple_main2()
{
    sh = 0;
    thread t1{f,1};
    thread t2{f,2};
    thread t3{f,3};
    t1.join();
    t2.join();
    t3.join();
    return 1;
}

#include <condition_variable>
//is a mechanism allowing one thread to wait for another.

#include <future>
//future and promise is that they enable a transfer of a value between two tasks without explicit use of lock
//when a task wants to pass a value to another, it puts the value into promise. (set_value() to put value operation)
//get that value from future (get() )
//if that value is not ready future.get() will halt the execution

//to connect a future and promise use packaged_task (packaged_task/future) or directly use (promise/future)
int sqr(int x)
{
    return x*x;
}
int simple_main3()
{
    using Task_type = int(int);             //FUNCTION TYPE   (used in std::function<int()> x; meaning it takes no args but returns an int)
    packaged_task<Task_type> pt0 {sqr};     //takes type of task as its template and task on its constructor argument
    packaged_task<Task_type> pt1 {sqr};     

    future<int> f0 {pt0.get_future()};
    future<int> f1 {pt1.get_future()};
    
    thread t1{move(pt0),9};
    thread t2{move(pt1),6};
    t1.join();
    t2.join();
    return f0.get()+f1.get();
}

//ASYNC
//dont even think of using async() for tasks that share resource needing locking
//with async we dont know how many threads will be used
//threads create their own stack; in async same stack

int* async_function(int* ar,int start,int end)
{
    for(int i = start; i< end; i++)
    {
        ar[i] = i*i;
    }
    return ar;
}
int* simple_main4()
{
    int ar[10000];
    auto f1 = async(async_function,ar,0,4000);
    auto f2 = async(async_function,ar,4000,8000);
    auto f3 = async(async_function,ar,8000,10000);
    f1.get();
    f2.get();
    return f3.get();
}

int main()
{
    //simple_main1();
    //simple_main2();
   // simple_main3();
   simple_main4();
}