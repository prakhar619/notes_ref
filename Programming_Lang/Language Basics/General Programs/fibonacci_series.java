import java.util.Scanner;
public class fibonacci_series
{
	public static double golden_ratio(int n)
	{
		n = n -1;
		final double fi = (1+Math.sqrt(5))/2;
		final double fi_i = (1-Math.sqrt(5))/2;
		
		double f_nth = ( Math.pow(fi,n) - Math.pow(fi_i,n) )/ Math.sqrt(5);
		return f_nth;
	}
	
	public static void main(String args[])
	{
		System.out.println("Enter the term of Fibonacci Series");
		Scanner Scan_obj =  new Scanner(System.in);
		System.out.println("OUTPUT:"+golden_ratio(Scan_obj.nextInt()));
		Scan_obj.close();
	}
}
		
