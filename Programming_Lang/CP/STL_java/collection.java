import java.util.List;
    //interface
    //ArrayList, LinkedList implements List interface
import java.util.Arrays;
    //class
import java.util.ArrayList;
    //class
public class collection
{
    public static void arraylistt()
    {
        List<String> list = Arrays.asList("Hello","world");
        List<String> anotherlist = new ArrayList<>();

        //List functions
            list.add("my world");
            list.forEach(System.out::println);
            for(String s : anotherlist)
            {
                System.out.println(s);
            }
            list.sort();
            q

    }
    public static void main()
    {

    }
}