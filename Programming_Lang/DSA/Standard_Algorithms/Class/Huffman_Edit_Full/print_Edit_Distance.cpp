//DP		Print Edit_Distance
//DP_5

//Convert string1 to string2
// OUTPUT code contain position of characters (not index)
//Hello#2@5#1k5#3M1
// Like 2 means delete; @ no meaning; 5 means 5th character(o)   => delete o

#include <string>
using namespace std;
int dp[100][100];

int min(int x,int y,int z)
{
	if(x <= y && x <= z)
	return x;
	else if(y <= x && y <= z)
	return y;
	else 
	return z;
}
int min(int x,int y)
{
	if(x>y)
	return y;
	return x;
}

int edit_distance_main(string str1, string str2, int len1, int len2)
{
	// If first string is empty, the only option is to insert all characters of second string into first
	if(len1 == 0)
		return len2*1;
	// If second string is empty, the only option is to remove all characters of first string
	if(len2 == 0)
	return len1*2;

	if(dp[len1][len2] != -1)
	return dp[len1][len2];
	
	if(str1[len1-1] == str2[len2-1] )
	{
		dp[len1][len2] = edit_distance_main(str1,str2,len1-1,len2-1);
		return dp[len1][len2];
	}
	//if last character not same ; try all and find min
				//insert					//remove					//replace
	dp[len1][len2] =  min( 1+edit_distance_main(str1,str2,len1,len2-1), 2+edit_distance_main(str1,str2,len1-1,len2), 3+edit_distance_main(str1,str2,len1-1,len2-1));
	return dp[len1][len2];
}

string code_addition(string st1, int key, int pos, char c = 'a')
	{
		if(key == 1) //insert
		return st1+"#"+"1"+c+to_string(pos+1);// USE DP TABLE TO GET CODE POS AND CHARACTER
		else if(key ==2)// delete
		return st1+"#"+"2"+"@"+to_string(pos);
		else
		return st1+"#"+"3"+c+to_string(pos);
	}
		

string edit_distance_dp(string str1,string str2)
{   
    int len1 = str1.length();
    int len2 = str2.length();
	for(int i = 0; i <= len1 || i <= len2; i++)
	for(int j = 0; j <= len1 || j <= len2; j++)
	dp[i][j] = -1;
	edit_distance_main(str1,str2,len1,len2);
	
	//Code 
	//Insert =  1<char><pos>	1c5
	//Delele =  2@<pos>		2@4
	//Replace = 3<char_final><pos>	3m2
	
	//Finally:
	//string1#op1#op2#op3...
	string output = str1;
	while(len1 > 0 && len2 > 0)
	{
		if(str1[len1-1] == str2[len2-1])
		{
			len1--;
			len2--;
		}
		else
		{
			int min_pos = min(dp[len1-1][len2],dp[len1][len2-1]);
			if( min_pos == dp[len1-1][len2] )
			{
				output = code_addition(output,dp[len1][len2] - min_pos,len1,str2[len2-1]);
				len1--;
			}
			else
			{
				output = code_addition(output,dp[len1][len2] - min_pos,len1,str2[len2-1]);
				len2--;
			}
		}
	}
	return output;
}
