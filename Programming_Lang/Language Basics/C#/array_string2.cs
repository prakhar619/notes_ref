using System;
class arrays
{
    public int[] array_ (int[] ar)
    {
        //array are implemented as object
        int[] int_1D = new int[10];
        int[,] int_2D = new int[10,30];
        int[,,,] int_multD = new int[1,2,3,4];
        int[][] intJagged = new int[5][];    //non square matrix; each internal array can be different size
            //arrays of arrays therefore no restriction that requires array to be 1D therefore int[][,] is also allowed

        for(int i = 0; i < int_1D.Length; i++)
        {
            int_1D[i] = i*i;
        }
        int[] better_way = {1,4,9,16,25};
        int[] worst_way = new int[] {1,4,9,16,25};

        // for(int i = 0; i < int_2D.Length; i++)
        // {
        //     for(int j = 0; j < int_2D[0,].Length; j++)
        //     {
        //         int_2D[i,j] = i*10+j;
        //     }
        // }
        // above code will be awful as Length of multidimesion array is total no of elements; like i 0->300 and no 0->10
        int [,] Better2D = {{1,2,3},{4,5,6},{6,7,8},{9,0,1}};

        for(int i =0; i <intJagged.Length; i++)
        {
             intJagged[i] = new int[i+1];
        }
        // [0]
        // [0,0]
        // [0,0,0]
        // [0,0,0,0]
        // [0,0,0,0,0]

        //Implicit array
        var vals = new[,] { {1.2,2.2},{1.11,8.6}};



        return int_1D;
    } 

    static int Main()
    {
        int[] noTemp = {1,2,3,5};
        arrays obj = new arrays();
        obj.array_(noTemp);
        return 0;
    }
}

class strings
{
    public string strings_ ()
    {
        //string are objects
        //immutable
        string simple = "Hello World!";
        
        char[] charAr = {'H','e','l','l','o'};
        string fromAr = new string(charAr);

        //String.Comparison
        //      .CurrentCulture
        //      .Ordinal
        //      .CurrentCultureIgnoreCase

        //Compare() is static

        // + is overloaded
        // string is alias of System.String

        //string Substring(int start,int length)

        //StringBuilder for mutable string
    }
}