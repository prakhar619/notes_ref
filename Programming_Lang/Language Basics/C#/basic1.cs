/* This is a comment
Multiline to be specific
*/

// Single Line comment

using System;
//System is a namespace

class class01 {
    //class name not necessarily file name
    static void Main()
    {
        //void return type
        //static function
        //caps Main M
        
        Console.WriteLine("This line is equivalent of System.Console.WriteLine"+" "+100);
        //Like java add all value in print statement

        //everyExpression atleast gives int
        // char + char -> int
        // (2byte) + (2byte) -> 4byte
    }

    void literal()
    {
        // Character Literals ''
        // String Literal " "
        // Verbatim String Literal (multiline string) @" "
        
        // Hexadecimal Literal
        //     0xFF is 255
            
        // Literal datatype implicitly by starting with minimum size
        // Integer Literal
        //     int -> uint -> long -> ulong
        // Fractional Literal
        //     double

        // Explicit datatype declaration
        // 12L is long (L or l)
        // 12U is uint (u or U)
        // 12UL is ulong
        // 10.2F
        // 10.2D   (not much use as default is double)
        // 12M is decimal (m or M)

    }



    void datatypes()
    {
        //Value Types: hold an actual value
            //int
            //double
            //bool
            //char
            //float
            //long
            
            //decimal
            //sbyte
            //short
            //uint
            //ulong
            //ushort
            //byte

        //char is not 8bit but 16bit unicode.

        // Dynamic Initialisation
        //     int x = pow(10,2);
        // Implicitly Typed Variable
        //     var x = 12.2
        //         finding x datatype from literal; here x is double
        //         only one var at a time; var x  =5, y = 10 is error
                


        //Reference Types: store refs to value types
        int x,y;

    }

    void operators()
    {
        //Arithmetic Operator
            // +,-,*,/,% (even on floating Dtype),++,--
        
        //Relational Operator
            // <,<=,>,>=,==,!=

        //Logical
            // &,|,^,&&,||,!

        //Assignment
            // =
                // x=y=z=100 allowed
            
        //Compound Statement
            // +=, -=, *= ,/=, %=, &=, |=, ^=

        //Bitwise Operator
            //&,|,^,~, << , >>

        //Bitwise Compound
            // &=, ...

        //Ternary
            // exp ? exp1 : exp2

        
    }

    void controlFlowStatement()
    {

        if(10 > 20)
        {
            //statement
        }
        else if(20 > 23)
        {

        }
        else
        {
            if(true)
            {}
            else{}
        }

        char a = 'a';
        switch(a)
        {
            //a can be char,byte,short,int,string,enum; floating point are not allowed; no two case same
            case 'b':
            break;
            default:

        }
        
        int j = 100;
        for(int i = 0, j = 20; i < 10; i++,j--)
        {
            //modified for loop
                // i < 10 can be any bool expression
                //leave any part as needed. for(;;) will give infinite loop
            //statement
        }

        while(j < 1000)
        {
            //statement
        }

        do{
            //statement
        }while(j < 1000)

        //foreach loop; cycles through elements of collection

        //break and continue keyword

        // goto (uncondictinal jump statement) [SPAGHETTI CODE]; 
            //use with labels
            Loop1:
                goto Loop1;
            //also use with case statement like goto case 'a'; or goto default;
        
        //foreach loop
        int[] ar = {1,2,3,4,5,6,7,8,9};
        foreach(int x in ar)
        {
            Console.WriteLine(x);
            //x is read-only

            //multidimension array is also diffent than c++
            //for(int x in ar2d)
                //this will give each value of ar starting from 0th row 0th element to last row last elem
        }

        // Name Hiding Not Allowed   
        //     int x = 10;
        //     if( x > 5)
        //     {
        //         int x = 20; //error
        //     } 


    }

    void casting()
    {
        //implicit cast (both need to satify)
            //compatible types are automatically converted; int and float are compatible; bool and int are not compactible 
            //destination type has range greater than source value (not source type)

        //explicit casting
            //Narrowing Conversion (truncation,mod with maxRange, 2's conversion)
            //(<type>) <value>; (int) 2.44

        //type Promotion rules (for expression)
            //each expression gives atleast int (char,sbyte,byte,ushort are are promoted to int for calculation); use cast to convert expression to smaller type => short b = (short) (10 + 10)
            //promotion only for compactible type
            //promotion based on availability of each variable in expression


    }

    void printtypes()
    {
        Console.Write("Without new line.");
        Console.WriteLine("With new line.");
        Console.Write("Argumented Print:{0},{1,10} or\t{3}","1st Arg","2nd Arg","3rd Arg","4th Arg");
        // {ArgumentNo,minimum_field_width}
        // {ArgumentNo:#,###:##} specifies print format for double. 0,003.33 and not 3.33404323
        // {0:C} monetary value like $100,102.02
    }

    void library()
    {
        System.Math.Sqrt(10);
        System.Math.Cos(10);

    }
}