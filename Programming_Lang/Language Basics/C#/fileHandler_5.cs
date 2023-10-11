
using System.Diagnostics;
using System.IO;

public class fileHandler_5
{
	public  void data()
	{
		StreamWriter fObj = new StreamWriter("./Sample.txt");
		fObj.WriteLine("This is the first line");
		fObj.WriteLine("Stan");
		fObj.Flush();
		fObj.Close();

	}

	public void read()
	{
		StreamReader sr = new StreamReader("./Sample.txt");
		sr.BaseStream.Seek(0, SeekOrigin.Begin);

		string str1 = sr.ReadLine();
		while(str1 != null)
		{
			Console.WriteLine(str1);
			str1 = sr.ReadLine(); 
		}
		sr.Close();
	}
}
