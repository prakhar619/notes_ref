public class Array_2 
{
	public static void main(String[] args)
	{
		int arr[];	//declaration
		arr = new int[10]; //initialisation;  without initialisation, no store or access
		arr[0] = 10;
		//All array are dynamically allocated
		
		//Second Way
		int arr1[] = {1,2,3,4,5};
		System.out.println(arr1.length); // to get array length
		//Array length in java do not change; 
		//Fixed, Permanent

		//Third Way
		int[] arr2;
		//arr2[0] = 10 ;   //error

		
		
		//Multidimensional Array
		int twoD[][] = new int[4][5];//4 row 5 col
		
		//Second way
		int twoD1[][] = new int[4][];
		//later we can define cols of each row
		twoD1[0] = new int[10];
		twoD1[1] = new int[12];
		
		//Third way
		int twoD2[][] = {{1,2,3},{4,5,6},{7,8,9}};
		
		//Forth way
		int[][] twoD3;
		
		
		//Traversing
		for(int x: arr1)		//this method is readonly method
		{ System.out.println(x);	// changing x here wont change original arr1
		}
		
		for(int x[] : twoD2)
		{
			for(int y: x)
			{}
		}
		
		
		
		
	}
}
		
