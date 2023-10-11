
/* 
L(i) = 1 + max( L(j) )	where  0<j<1 and ar[j] < ar[i]
L(i) = 1 when  for all j < i => ar[j] > ar[i]
Our ans will like access a tree
{3,10,2,11,5}

L(5) = 1 + max( L(1), L3) )
L(4) = 1 + max( L(1), L(2), L(3) )
L(3) = 1;
L(2) = 1 + max( L(1) )
L(1) = 1

Ans 4;
Understanding recursion with loop is must
				\
		     \         \           \
		   \ \ \      \ \ \       \ \ \ 
		   
*/

//Time Complexity: O(2^N)
//Space Complexity: O(1)
int max(int a,int b)
{
	if(a > b)
	return a;
	return b;
}

int LIS_brute(int *ar,int index, int &maxi)
{
	if(index == 0)
		return 1;
	int maxii = 0;
	
	for(int i = 0; i< index; i++)
	{	
		int L_i = LIS_brute(ar,i,maxi);
		if( ar[index] > ar[i] )
		{
			maxii = max(L_i,maxii);
		}
	}
	maxi = max(maxi,maxii + 1);
	return 1 + maxii;
}
int LIS_brute_main(int *ar,int len)
{
	int max = 0;
	
	LIS_brute(ar,len-1,max);
	return max;
}


/* Now instead of finding everytime L(i) we are going to store it in an array
Ex: {10,22,9,33,21,50,41,60}
L(8) = 1 + max( L(1), L(2), L(3), L(4), L(5), L(6), L(7) )
L(7) = 1 + max( L(1), L(2), L(3), L(4), L(5) )
L(6) = 1 + max( L(1), L(2), L(3), L(4), L(5) )
L(5) = 1 + max( L(1), L(3) )
L(4) = 1 + max( L(1), L(2), L(3) )
L(3) = 1 
L(2) = 1 + max( L(1) )
L(1) = 1

We have subproblems and they are overlapping
*/
int dp[100];
int max(int a,int b)
{
	if(a > b)
	return a;
	return b;
}

int LIS_dp(int *ar,int index,int &maxi)
{
	if(index == 0)
		return 1;
	int maxii = 0;
	
	for(int i = 0; i< index; i++)
	{
		if(dp[i] == -1)
			dp[i] = LIS_dp(ar,i,maxi);
		if( ar[index] > ar[i] )
		{
			maxii = max(dp[i],maxii);
		}
	}
	maxi = max(maxii+1,maxi);
	return 1 + maxii;
}

int LIS_dp_main(int *ar,int len)
{
	for(int i = 0; i < len; i++)
	dp[i] = -1;
	int max = 0;
	
	LIS_dp(ar,len-1,max);
	return max;
}
	
 
			
	
