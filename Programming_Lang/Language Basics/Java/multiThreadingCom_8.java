//wait;notify;notifyAll();

//wait(); tells calling thread to give up the monitor and go to sleep. So that other thread can enter monitor
//notify(); wakes up the thread that can wait()
//notifyAll(); wakes up all the thread that called wait


//spurious wakeup: when thread wakes without notify/notifyAll
    //therefore recommended to put wait() inside loop that checks condiction that thread is waiting;

//Our Aim: Producer uses object then consumer then producer then consumer and so on...
/*
class Q
{
    int n;
    synchronized int get()
    {
        System.out.println("Got:"+n);
        return n;
    }
    synchronized void put(int n)
    {
        this.n=n;
        System.out.println("Put:"+n);
    }

}

class Producer implements Runnable
{
    Q obj;
    Thread t;
    int max = 2000;
    Producer(Q obj)
    {
        this.obj = obj;
        t = new Thread(this,"Producer");
    }
    public void run()
    {
        int i = 0;
        while(i <=  max)
        {
            obj.put(i++);
        }

    }
}
class Consumer implements Runnable
{
    Q obj;
    Thread t;
    int max = 2000;
    Consumer(Q obj)
    {
        this.obj = obj;
        t = new Thread(this,"Consumer");
    }
    public void run()
    {
        while(obj.n < max)
        obj.get();
    }
}

class multiThreadingCom_8
{
    public static void main(String args[])
    {
        Q obj = new Q();
        Producer p = new Producer(obj);
        Consumer c = new Consumer(obj);

        p.t.start();
        c.t.start();
    }
}
*/
//Obj is monitor therefore can be accessed by one thread at a time(starting with producer). it does not relinquish control and goes on producing on its own.
//After some time (may be java run time) monitor is passed to the waiting thread(consumer) which it also does not relinquish control on its own.
//Therefore grps/phases of put and get
class Q
{
    int n;
    boolean flag = false;
    
    synchronized int get()
    {
        
        while(!flag)   //wait when flag is false
        {
            try{
                wait();
            }
            catch(InterruptedException e)
            {
            System.out.println("InterruptedException caught");
            }
        }
        
        
        //runs when flag is true
        System.out.println("Got:"+n);
        flag = false;
        notify();
        return n;
    }
    synchronized void put(int n)
    {
        
        while(flag)//wait when flag is true;
        {
            try{
                wait();
            }
            catch(InterruptedException e)
            {
                System.out.println("Interrupted Exception caught");
            }
        }
        
        
        this.n=n;
        flag= true;
        System.out.println("Put:"+n);
        notify();
    }
}
class Producer implements Runnable
{
    Q obj;
    Thread t;
    int max = 2000;
    Producer(Q obj)
    {
        this.obj = obj;
        t = new Thread(this,"Producer");
    }
    public void run()
    {
        int i = 0;
        while(i <= max)
            obj.put(i++);

    }
}
class Consumer implements Runnable
{
    Q obj;
    Thread t;
    int max = 2000;
    Consumer(Q obj)
    {
        this.obj = obj;
        t = new Thread(this,"Consumer");
    }
    public void run()
    {
        while(obj.n < max)
        obj.get();
    }
}
class multiThreadingCom_8
{
    public static void main(String args[])
    {
        Q obj = new Q();
        Producer p = new Producer(obj);
        Consumer c = new Consumer(obj);
        p.t.start();
        c.t.start();
    }
}

//Assume there are 2 states wait and notify
//Either a thread can be in monitor or not
//Wait means if waiting to enter the monitor
//notify means i am relinquishing control and wait thread can take over

// zero means thread is waiting

/* wait and notify used by both
            P       C
            1       0
            0       1
            2       0
            0       2
 */  

 /*no one uses wait and notify
        P       C
  *     1       0
        2       0
        3       0
        4       0
        5       0
        6       0
        0       6
        0       6
        0       6
        0       6
        0       6
  */

  /*notify used;wait not used //same as simple async case
            P           C
            1           0
            2           0
            3           0
            4           0
            5           0
            0           5
            0           5
            0           5
            0           5
*/






