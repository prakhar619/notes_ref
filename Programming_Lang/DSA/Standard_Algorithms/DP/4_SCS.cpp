//string A, string B ------------> length of shortest common supersequence (int)
// Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
// Output:  9 (AGXGTXAYB)

// uses lcs(longest common subsequence)
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
/*
len(A) + len(B) - lcs(A,B)
*/
#include<string>
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
int scs(string A,string B, int len_A, int len_B)
{
	return len_A + len_B - lcs(A,B,len_A,len_B);
}
