//DEADLOCK: when both thread_class wait for each other to leave monitor; but no one does it before leaving their monitor(2 obj and 2 thread_class involved)
//Suspending,Resuming,Stopping Thread: No exclusive function. wait,notify,notifyAll used.
/*/Thread State:
Value:  Blocked         :suspended execution because waiting to acquire lock
        New             :thread_class has not begun execution
        Runnable        :currently executing or will execute when it gains access to cpu
        Terminated      :completed execution
        Timed_waiting   :sleep(); timeout version wait(),notify();
        Waiting         :non timeout version wait(),notify()
*/

/* 
 *              New    
 *  Blocked     Runnable       Waiting/Timed waiting
 *              Terminated
 */

 /*Factory Method: Create and Start thread_class in same function */
public class multiThreadextra_8
{
    public static void main(String args[])
    {
        thread_class k = thread_class.create_n_start();//static function therefore obj not needed
        System.out.println(k.t.isAlive());
    }
}

class thread_class implements Runnable
{
    Thread t;
    thread_class()
    {
        t = new Thread(this);//this is important
        System.out.println("New Thread Created");
    }

    //Factory Method
    public static thread_class create_n_start()
    {
        thread_class obj = new thread_class();
        obj.t.start();
        System.out.println("Thread Started");
        return obj;
    }

    public void run()
    {
        System.out.println("HE");
        try
        {
            for(int i = 0; i< 10; i++)
            {
                System.out.println(i);
                Thread.sleep(1000);
            }
        }
        catch(InterruptedException e)
        {
            System.out.println("Interrupted");
        }
        finally{
            System.out.println("Thread ended");
        }
    }

}