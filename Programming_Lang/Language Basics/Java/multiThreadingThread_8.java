//extending class must override run method

public class multiThreadingThread_8 {
    public static void main(String args[])
    {
        newThread t=  new newThread();
        t.start();

        try{
            for(int i = 5; i> 0; i--)
            {
                System.out.println("Main Thread:"+i);
                Thread.sleep(1000);
            }
        }
            catch(InterruptedException e)
            {
                System.out.println("Main Thread Interrupted");
            }
        }
    }

//Run must be overwritten
//rest method are optional to overwrite
class newThread extends Thread
{
    newThread()
    {
        super("New Threaductor");
        System.out.println("New Thread:"+this);
    }

    public void run()
    {
        int ar[] = new int[10];
        try{
            for(int i = 0; i <= 9; i++)
            {
                ar[i] = i*i;
                System.out.println("Ar["+i+"] is:"+ar[i]);
                Thread.sleep(1000);
            }
        }
        catch (InterruptedException e)
        {
            System.out.println("Interrupted in between");
        }
    }
}