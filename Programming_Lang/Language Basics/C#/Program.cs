// See https://aka.ms/new-console-template for more information
using System;   //import System package for accessing classes

using System.Drawing;
using System.Globalization;
using System.Security.Cryptography.X509Certificates;

namespace basic; // same as namespace std

    public class basics_1
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Hello World");   //System.console.writeline("Hello World");
            Console.WriteLine("New line ");
            variables();
            read();


            oops_4 obj = new oops_4("White");
            Console.WriteLine(obj.color);


            obj.Passcode = "1234";
            Console.WriteLine(obj.Passcode);

        oops_4_1 obj_1 = new oops_4_1("HElo");
        Console.WriteLine(obj_1.color);

        fileHandler_5 ffile = new fileHandler_5();
        ffile.data();
        Console.ReadKey();

        casting();
        }

        static void variables()
        {
            string st1 = "Hello World";
            int a = 10;
            double d = 1.23;
            bool b = true;  //unlike python
            char c = 'a';

            Console.WriteLine(a + d);
            Console.WriteLine(b);
            Console.WriteLine(c);
            Console.WriteLine(st1+c);

            long l = 12344342L;
            double d1 = 1.23234D;
            float f = 122.23F;
            float f1 = 35e5F;
            double d2 = 35E5D;
            Console.WriteLine(l);
            Console.WriteLine(d1);
            Console.WriteLine(f);
            Console.WriteLine(f1);
            Console.WriteLine(d2);
        }
        static void casting()
        {
            int i_d = (int)2.23;
            Console.WriteLine("2.23 converted to int:" + i_d);

        //inter-numerical data types
        //int to double
        //Console.WriteLine(Convert.ToDouble(myInt));
        //double to int
        //Console.WriteLine((int)myDouble);
        //Console.WriteLine(Convert.ToInt32(myDouble));

        //char,string->number
        Console.WriteLine("String (5) and string (121) converted to int and added" + Convert.ToInt("5") + Convert.ToInt("121"));

        //char->ascii_number

        //number->string

        //number->ascii_char

        //Console.WriteLine(Convert.ToString(myInt));    // convert int to string

        //Console.WriteLine(Convert.ToString(myBool));   // convert bool to string
    }

    static void read()
        {
            string userName =  Console.ReadLine();  //returns a string
            int rollNo = Convert.ToInt32(Console.ReadLine());   //Use convert.to...
        }

        static void condictional()
        {
            if (20 > 18)
            {
                Console.WriteLine("20 is greater than 18");
            }
            else if (20 == 18)
            {
                Console.WriteLine("20 is equal to 18");
            }
            else
            {
                Console.WriteLine("20 is smaller to 18");
            }

            int ternary = 20 > 18 ? 20 : 18;
            Console.WriteLine(ternary);

            switch (ternary)
            {
                case 20:
                    Console.WriteLine("x is 20");
                    break;
                default:
                    Console.WriteLine("x is not 20");
                    break;
            }
        }
            public static void looping()
            {
                int i = 0;
                do
                {
                    Console.WriteLine(i);
                    i++;
                } while (i <= 20);

                for(int j = 0; j <=20; j++)
                {
                    if (j == 15)
                        continue;
                    Console.WriteLine(j);
                }
                  
                while( i <= 40)
                {
                    Console.WriteLine(i);
                    ++i;
                }

                string[] st_ar = { "123", "456", "789", "1234" };
                foreach(string j in st_ar)
                {
                    Console.WriteLine(j);
                }

              
            }
        
    }


/*
 * Unlike java, C# file does not need to match class name but usually done.
*/

/* C# data types
 * int      4bytes
 * double   8bytes
 * char     2bytes
 * string   2bytes per char
 * bool     1bit
 * 
 * long     8bytes
 * float    4bytes
 */

/*
 * + - * / ^
 * % mod
 * ++ --
 * += -= ^=
 *Binary Operators
 *|| OR
 *>>
 *<<
 *&& AND
 *|=
 *&=
 *! NOT
 *Comparsion Operator
 *==
 *!=
 *>
 *<
 *<=
 *>=
 */


/* Keywords
 * const    keyword for variable not to change its value
 */

/* + operator is overloaded
 */

/* casting
 * implicit casting
 * char - int - long - float - double
 * explicit casting
 * double - float - long - int - char
 */



