/*Thread Priorties
 * Context Switch
 *      1.A thread can voluntarily relinquish control.All other threads are examined and highest-priorty thread is run.
 *      2.A lower thread is forcefully removed by high priorty thread.[Preemptive Multitasking]       
 *      3.Same lvl thread either slice of cpu time or voluntarity yield to peers.
 */

 /*Synchronisation */

 //Thread Class and Runnable interface



//Main Thread is the original program, all thread spawned from it, and it must be the last one to end.

//Main->start()->run()

public class multiThreadingRunnable_8 {
    public static void thread_methods()
    {
        Thread t = Thread.currentThread(); //return main thread
        System.out.println("Before:"+t);
        t.setName("Main Thready");
        System.out.println("After:"+t);
        System.out.println("ThreadName:"+t.getName());
        System.out.println("ThreadPriorty:"+t.getPriority());//Thready prirorty default 5
        System.out.println("ThreadAlive:"+t.isAlive());
        
        try{
        for(int n = 5; n > 0; n--)
        {
            System.out.println(n);
            Thread.sleep(1000);//time in ms (millisecond)
            //Thread.sleep(1000) will also work
            //sleep can throw InterruptedException
        }}
        catch(InterruptedException e)
        {
            System.out.println("Thready interupted:"+e);
        }
        
    }

    public static void main(String args[])
    {
        thread_methods();
        implementing_runnable obj = new implementing_runnable();
        obj.th.start();
        implementing_runnable2 obj2 = new implementing_runnable2();
        obj2.th.start();
        System.out.println(obj2.th.isAlive());
        try{
        obj2.th.join(); //stop main thread till obj2.th thread finishes.
        }
        catch (InterruptedException i)
        {
            System.out.println("JOIN interrupted");
        }
        finally
        {
        System.out.println("PAST JOIN");
        }
    }
}

//NEW THREAD
class implementing_runnable implements Runnable
{
        Thread th;
        implementing_runnable()
        {
            th= new Thread(this,"New Threader");
            System.out.println("New Thread created "+th);
        }

        public void run()//entry point for new thread
        {
            try
            {
                for(int i = 1; i <=5 ; i++)
                {
                    System.out.println(i);
                    Thread.sleep(1000);
                }
            }
            catch (InterruptedException e)
            {
                System.out.println("Interrupted New Threader "+e);
            }
        }
}

//NEW THREAD
class implementing_runnable2 implements Runnable
{
        Thread th;
        implementing_runnable2()
        {
            th= new Thread(this,"New Threader2");
            System.out.println("New Thread 2 created "+th);
        }

        public void run()
        {
            try
            {
                for(int i = 1; i <=5 ; i++)
                {
                    System.out.println(i);
                    Thread.sleep(1000);
                }
            }
            catch (InterruptedException e)
            {
                System.out.println("Interrupted New Threader "+e);
            }
        }
}