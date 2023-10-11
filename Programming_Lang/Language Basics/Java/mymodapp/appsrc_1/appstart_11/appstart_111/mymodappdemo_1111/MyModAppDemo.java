package appstart_111.mymodappdemo_1111;
import appfuncs_111.simplefuncs_1111.SimpleMathFuncs;
//not only we are requiring/exporting but we also are importing package;
public class MyModAppDemo {
    public static void main(String args[])
    {
        if(SimpleMathFuncs.isFactor(2,10))
        System.out.println("2 is a factor of 10");
        System.out.println("Smallest factor common to both 35 and 105 is "+SimpleMathFuncs.lcf(35,105));
        
    }
}
