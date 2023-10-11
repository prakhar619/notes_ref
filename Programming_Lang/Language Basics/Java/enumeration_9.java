public class enumeration_9 {
    public static void main(String args[])
    {
        color bitt = color.red;
        //enum famous for case switch
        switch (bitt)
        {
            case red:   //we dont need to write color.red
            System.out.println("COLOR is reD");
            break;
            case green:
            System.out.println("COLOR is greeN");
            break;
        }


        //All enum constains 2 predefined methods
        //values(): returns an array of list of enum constants, data type: enum
        //valueOf(): return corresponding enum const associated with string passed

        color value_array[] = color.values();
        for(color t: value_array)
        System.out.println(t);


        bitt = color.valueOf("green");
        System.out.println("Bitt value is:"+bitt);



        //better use of enum as class
        System.out.println(betterColor.red.return_color());
        for(betterColor a : betterColor.values())
        {
            System.out.println(a+" "+a.return_color());
        }
    }



}

//enumeration variables are constant
enum color
{
    red,green,blue//enumueration constants
}

//Java enum are class type; but do not require new keyword
//enum have constructors,instance variables,method and implement interfaces
enum betterColor
{
    red(255),green(255),blue(255);
    
    //instance variable
    int max = 255;
    int min = 0;
    private int val;

    //constructor
    betterColor(int px)
    {
        val = px;
    }

    //method
    int return_color()
    {
        return val;
    }
}

//enum cant inherit
//all enum are inherit one automatically:java.lang.Enum
//Enum class: ordinal(), compareTo()
//ordinal():    order when declaring enum const;    red:0, green:1, blue:2
//compareTo(enum obj):  compare ordinal values of 2 enum obj const;         0 when same     invoking const greater then +ve
//equals():         no error but true only when enum obj of both are same enum class and ordinal value same



