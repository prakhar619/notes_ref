using System;

public class libraries_3
{
	public static void main()
	{
		int x = Math.Max(3, 5);
		int y = Math.Min(3, 5);
		int x2 = (int)Math.Sqrt(x);
		int y2 = Math.Abs(-3);
		double x3 = Math.Round(4.53);
	}

	public static void string1()
	{
		string st1 = "Hello world";
		int len = st1.Length;
		string ST1 = st1.ToUpper();
		string st_1 = st1.ToLower();
		string st = string.Concat(st1, ST1);
		string interpolation = $"String is put in place {st1} and here {ST1}";
		Console.WriteLine(st1[3]);
		Console.WriteLine(st1.IndexOf("e"));
		Console.WriteLine(st.Substring(4));
		/* Escape Character
		 * \'
		 * \"
		 * \\
		 * \n	new line
		 * \t	tab
		 * \b	backspace
		 */	 
	}
}
