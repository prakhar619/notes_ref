//string A, string B -----> string C (SCS
// Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
// Output:  9 (AGXGTXAYB)

// uses lcs
// Time Complexity : O(m*n)
// Space Complexity: O(m*n)


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

string scs_string(string A,string B)
{
    int max_index = max(A.size(),B.size());
    for(int i = 0; i< max_index ; i++)
    for(int j = 0; j < max_index; j++)
    dp[i][j] = -1;
	string C = "";
	lcs(A,B,A.size(),B.size());
	int i = A.size(),j = B.size();
	
	while(i > 0 && j > 0)
	{
		if(A[i-1] == B[j-1])
		{
			C = A[i-1] + C;
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1])
		{
			C = A[i-1] + C;
			i--;
		}
		else
		{
			C = B[j-1] + C;
			j--;
		}
	}
	if(i > 0)
		for(;i >0; i--)
		C = A[i-1]+C;
	if(j > 0)
		for(;j >0; j--)
		C = B[j-1]+C;
	
	return C;
}
