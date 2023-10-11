import java.util.ArrayList;
import java.util.Collections;
public class base_convertion {
    ArrayList<Integer> converted_no = new ArrayList<Integer>();
    base_convertion(int base,int num)
    {
        while(num != 0)
        {
            converted_no.add(num%base);
            num = num/base;
        }
        Collections.reverse(converted_no);
    }
    //Operator Overload + - * /

    public void print()
    {
        for(int i:converted_no)
        System.out.print(i+":");
        System.out.println();
    }


    public static void main(String args[])
    {
        base_convertion obj = new base_convertion(5, 51);
        obj.print();
    }
}
