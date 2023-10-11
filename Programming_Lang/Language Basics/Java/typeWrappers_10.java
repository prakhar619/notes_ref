public class typeWrappers_10 {
    //In java primitive datatypes are passed as value rather then reference
    //To have primitive datatypes as object use typeswrappers
    //typewrapper have autoboxing and autounboxing meaning automatic conversionn to respective primitive datatype and so forth.
    public static void main(String args[])
    {
        //Character
        Character C = Character.valueOf('a');
        char c = C.charValue();

        //Boolean
        Boolean B = Boolean.valueOf(true);
        Boolean B_ = Boolean.valueOf("anything else is false");//when string "true" is true everything else is false
        boolean b = B.booleanValue();
        boolean b_ = B_.booleanValue(); 

        //Numeric Type          //Abstract class Number
        byte i = 123;
        Byte B_n = Byte.valueOf(i);
        Double d = Double.valueOf(2.34);
        Integer i_n = Integer.valueOf(129);
        Integer i_nn = Integer.valueOf("123");  //throws NumberFormatException
        Long L=Long.valueOf(123232312);
        Float F = Float.valueOf(12.23f);
        
        //doubleValue(),floatValue(),

        i_n++;//autoboxing and autounboxing at same time
        System.out.println(100+i_n);//unboxing

        //Almost everywhere int is used,we can use Integer.
        //Although not prescribed as too slow


    }
}
