//Synchronisation and Performance

//race condiction
// threads racing to each other to access same object (objects.method).
// may notice sometime, sometime not


//monitor is an object and not method;


public class multiThreadingPerformancle_8 {
    /* 
    public static void main(String args[])
    {
    
        System.out.println("Program Started");
        thread obj1 = new thread("1",1);
        thread obj2 = new thread("2",2);
        thread obj3 = new thread("3", 3);
        thread obj4 = new thread("4",4);
        thread obj5 = new thread("5",5);
        thread obj6 = new thread("6",6);
        thread obj7= new thread("7", 7);
        thread obj8 = new thread("8",8);
        thread obj9 = new thread("9",9);
        thread obj10 = new thread("10",10);
        thread obj11 = new thread("11",1);
        thread obj12 = new thread("12",2);
        thread obj13 = new thread("13", 3);
        thread obj14 = new thread("14",4);
        thread obj15 = new thread("15",5);
        thread obj16 = new thread("16",6);
        thread obj17= new thread("17", 7);
        thread obj18 = new thread("18",8);
        thread obj19 = new thread("19",9);
        thread obj20 = new thread("20",10);
        obj1.t.start();
        obj2.t.start();
        obj3.t.start();
        obj4.t.start();
        obj5.t.start();
        obj6.t.start();
        obj7.t.start();
        obj8.t.start();
        obj9.t.start();
        obj10.t.start();
        obj11.t.start();
        obj12.t.start();
        obj13.t.start();
        obj14.t.start();
        obj15.t.start();
        obj16.t.start();
        obj17.t.start();
        obj18.t.start();
        obj19.t.start();
        obj20.t.start();

    }
    */
    //Synchronization code
    //Main function
    public static void main(String args[])
    {
        syncro obj = new syncro();
        System.out.println("Program Started");
        syncroThread obj1 = new syncroThread(obj,"1",1);
        syncroThread obj2 = new syncroThread(obj,"2",2);
        syncroThread obj3 = new syncroThread(obj,"3", 3);
        syncroThread obj4 = new syncroThread(obj,"4",4);
        syncroThread obj5 = new syncroThread(obj,"5",5);
        syncroThread obj6 = new syncroThread(obj,"6",6);
        syncroThread obj7= new syncroThread(obj,"7", 7);
        syncroThread obj8 = new syncroThread(obj,"8",8);
        syncroThread obj9 = new syncroThread(obj,"9",9);
        syncroThread obj10 = new syncroThread(obj,"10",10);
        syncroThread obj11 = new syncroThread(obj,"11",1);
        syncroThread obj12 = new syncroThread(obj,"12",2);
        syncroThread obj13 = new syncroThread(obj,"13", 3);
        syncroThread obj14 = new syncroThread(obj,"14",4);
        syncroThread obj15 = new syncroThread(obj,"15",5);
        syncroThread obj16 = new syncroThread(obj,"16",6);
        syncroThread obj17= new syncroThread(obj,"17", 7);
        syncroThread obj18 = new syncroThread(obj,"18",8);
        syncroThread obj19 = new syncroThread(obj,"19",9);
        syncroThread obj20 = new syncroThread(obj,"20",10);
        obj1.t.start();
        obj2.t.start();
        obj3.t.start();
        obj4.t.start();
        obj5.t.start();
        obj6.t.start();
        obj7.t.start();
        obj8.t.start();
        obj9.t.start();
        obj10.t.start();
        obj11.t.start();
        obj12.t.start();
        obj13.t.start();
        obj14.t.start();
        obj15.t.start();
        obj16.t.start();
        obj17.t.start();
        obj18.t.start();
        obj19.t.start();
        obj20.t.start();
    }
    
    

}


class thread implements Runnable
{
    Thread t;
    int ar_th[];
    thread(String name,int priorty){
        t = new Thread(this, name);
        t.setPriority(priorty);
        System.out.println(name+" Thread started.");
    }

    public void run()
    {
        //Code to check execution order
        
        ar_th = new int[10];
        try{
        for(int i = 0; i < 10; i++)
            {
                ar_th[i] = i*i;
                System.out.println("Ar["+i+"] is:"+ar_th[i]+"   Name:"+t.getName());
                Thread.sleep(1000);
            }
        }
        catch (InterruptedException e)
        {
            System.out.println("Interrupted:"+t);
        }
        finally{
            System.out.println("Thread Ended: Thread Name:"+t.getName()+" Thread Priorty:"+t.getPriority());
        }
    }
}




//Synchronisation code
//Threads
class syncroThread implements Runnable
{
    Thread t;
    syncro obj;
    syncroThread(syncro ob, String name,int priorty)
    {
        obj = ob;
        t = new Thread(this,name);
        t.setPriority(priorty);
    }
    public void run()
    {
        //either make the method called synchronized like this (synchronized public void function) or synchronized the object like this;
        //synchronized object when you dont have access to function.
        synchronized(obj){
        obj.functio(t.getName());
        }
    }
}

//Synchronisation code
//UNSynchronization function
class syncro 
{
    // keyword synchronized causes function to be avaiable to only one thread at a time;
    // all other thread will wait till current thread exit this method

    
    //synchronized void functio(String msg){
    void functio(String msg){
        System.out.print("[");
        System.out.print(msg);
        try{
        Thread.sleep(1000);
        }
        catch (InterruptedException e)
        {
            System.out.println("Interrupted:"+msg);
        }
        finally
        {
            System.out.print(" "+msg+"]");
        }

    }
}


