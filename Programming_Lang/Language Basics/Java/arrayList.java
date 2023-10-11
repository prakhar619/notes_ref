import java.util.ArrayList; //vector equivalent
/* Function and Method
 * add()
 * get()
 * set()
 * remove()
 * clear()
 * size()
 */
public class arrayList
{
    public static void main(String args[])
    {
    ArrayList<Integer> ar = new ArrayList<Integer>();
    ar.add(10); //push_back
    ar.add(20);
    ar.add(23);

    ar.set(2,28);
   // ar.set(3,20);//error
    ar.remove(0);
    
    
    for(int i = 0; i< ar.size(); i++)
    System.out.println("Element at index "+i+" is "+ar.get(i)); // ar[i] for array not arraylist
    
    for(int i: ar)
    System.out.println(i);
    
    ar.clear();


    ArrayList<String> ar_s = new ArrayList<String>();
    ArrayList<Character> ar_c = new ArrayList<Character>();
    ArrayList<Double> ar_d = new ArrayList<Double>();

    
}
}
