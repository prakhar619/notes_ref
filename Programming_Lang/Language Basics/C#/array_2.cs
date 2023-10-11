using System;
using System.Linq;  //array functions

public class array_2
{
	public static void main()
	{
		string[] st_ar;
        //st_ar = { "Name", "Address", "ROll No"};// this will give error
        st_ar = new string[] { "Name", "Address", "ROll No" };
		int[] num = { 1, 2, 3, 4, 5, 6, 7, 8 };

		Console.WriteLine(st_ar[2]);
		num[2] = 30;
		int len = num.Length;

        // Create an array of four elements, and add values later
        string[] cars = new string[4];

        // Create an array of four elements and add values right away 
        //string[] cars = new string[4] { "Volvo", "BMW", "Ford", "Mazda" };

        // Create an array of four elements without specifying the size 
        //string[] cars = new string[] { "Volvo", "BMW", "Ford", "Mazda" };

        // Create an array of four elements, omitting the new keyword, and without specifying the size
        //string[] cars = { "Volvo", "BMW", "Ford", "Mazda" };

        foreach(string i in cars)
        {
            Console.WriteLine(i);
        }

        Array.Sort(cars);
        foreach(string i in cars)
        {
            Console.WriteLine(i);
        }

        Console.WriteLine(num.Max());
        Console.WriteLine(num.Min());
        Console.WriteLine(num.Sum());

    }

    public static void multidim_ar()
    {
        int[,] num = { { 1, 2, 3 }, { 4, 5, 6 } };
        int[,,] num2 = { { { 1, 2, 3 }, { 4, 5, 6 } }, { { 6, 7, 8 }, { 8, 9, 0 } } };

        Console.WriteLine(num[0, 2]);
        Console.WriteLine(num2[1, 2, 2]);

        foreach (int i in num)
        {
            Console.WriteLine(i);
        }
        foreach (int i in num2)
        {
            Console.WriteLine(i);
        }

        Console.WriteLine(num.GetLength(0));
        Console.WriteLine(num2.GetLength(0));
    }
}

