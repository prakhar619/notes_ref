//string A, string B, int len(A), int len(B)  ----------> length of longest common subsequence (int)
//Subsequence vs substring:  AABBCDE	Subsequence: ABCE 	Substring: BCDE 
 
// Input: S1 = “AGGTAB”, S2 = “GXTXAYB”
// Output: 4 (GTAB)

//Brute Force
// TIme Complexity: O(2^N)
// Space Complexity: O(1)
#include<string>
using namespace std;
int max(int a,int b)
{
	if(a> b)
	return a;
	return b;
}
int lcs(string A,string B,int len_A,int len_B)
{
	if(len_A == 0 || len_B == 0)
	return 0;
	if(A[len_A -1] == B[len_B-1])
	{   
	    
	    return 1 + lcs(A,B,len_A -1, len_B -1);
	}
	else
	return max(lcs(A,B,len_A, len_B -1),lcs(A,B,len_A -1, len_B));
}


//DP
// Also main function need to include part where dp[i][j] = -1 for all 100 values;
//TIme Complexity: O(m*n)		//Filling up dp table
//Space Complexity: O(m*n)
#include<string.h>
using namespace std;
int dp[100][100];
int max(int a,int b)
{
	if(a> b)
	return a;
	return b;
}
int lcs(string A, string B, int len_A, int len_B)
{
	if(len_A == 0 || len_B == 0)
	return 0;
	if(A[len_A-1] == B[len_B -1])
	return dp[len_A][len_B] = 1+lcs(A,B,len_A-1,len_B-1);
	if(dp[len_A][len_B] != -1)
	return dp[len_A][len_B];
	return dp[len_A][len_B] = max(lcs(A,B,len_A,len_B-1),lcs(A,B,len_A-1,len_B));
}
