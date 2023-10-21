//Dynamic Programming 		EDIT DISTANCE

/*
Convert string1 to string2
Given two strings str1 and str2 and below operations that can be performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  
Insert
Remove
Replace

Each of the above operation have 1,2,3 cost;
*/

#include <string>
using namespace std;
int min(int x,int y,int z)
{
	if(x <= y && x <= z)
	return x;
	else if(y <= x && y <= z)
	return y;
	else 
	return z;
}

int edit_distance_brute(string str1, string str2, int len1, int len2)
{
	// If first string is empty, the only option is to insert all characters of second string into first
	if(len1 == 0)
	return len2*1;
	
	// If second string is empty, the only option is to remove all characters of first string
	if(len2 == 0)
	return len1*2;
	
	if(str1[len1-1] == str2[len2-1] )
	return edit_distance_brute(str1,str2,len1-1,len2-1);
	
	//if last character not same ; try all and find min
				//insert					//remove					//replace
	return min( 1+edit_distance_brute(str1,str2,len1,len2-1), 2+edit_distance_brute(str1,str2,len1-1,len2), 3+edit_distance_brute(str1,str2,len1-1,len2-1));
	
}




/*Using DP*/


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

int edit_distance_dp(string str1,string str2)
{   
    int len1 = str1.length();
    int len2 = str2.length();
	for(int i = 0; i <= len1 || i <= len2; i++)
	for(int j = 0; j <= len1 || j <= len2; j++)
	dp[i][j] = -1;
	edit_distance_main(str1,str2,len1,len2);
	return dp[str1.length()][str2.length()];
}
	
