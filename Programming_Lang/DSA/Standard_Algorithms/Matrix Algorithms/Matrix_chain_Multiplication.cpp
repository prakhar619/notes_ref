// Matrix dimensions list (array) --------> Least Cost (to multiply) (int)
// Input: A(3*4)B(4*7)C(7*3)D(3*1)E(1*6) Then input: {3,4,7,3,3,6}


//Brute Force
//Time Complexity: O(2^N) Exponential
//Space Complexity: O(1)

/* m[i,j] = min( m[i,k]+m[k+1]+p[i]*p[k]*p[j] ) 	where k->i to j
Also m[i,i] = 0
To understand this refer to notez as this is highly theoretical.
*/
#define INT_MAX 2100000000
int min(int a,int b)
{
	if(a> b)
	return b;
	return a;
}
int matrixchainMult(int* p, int i, int j_lastIndex)
{
	
	if(i == j_lastIndex)
	return 0;
	
	int k = i;
	int min_mult = INT_MAX;
	int count;
	
	for(; k< j_lastIndex; k++)
	{
		count = matrixchainMult(p,i,k) + matrixchainMult(p, k+1, j_lastIndex) + p[i-1]*p[j_lastIndex]*p[k];
		min_mult = min(count, min_mult);
	}
	return min_mult;
}

//DP Recursion
//Time Complexity: O(N^3)
//Space Complexity: O(N^2)

/*Highly Theoretical REFER NOTEZ */

#define INT_MAX 2100000000
int m[100][100];
int min(int a,int b)
{
	if(a> b)
	return b;
	return a;
}
int buildmatrixChain(int *p, int i, int j)
{
	if(i == j)
	return 0;
	if(m[i][j] != -1)	//meaning m[i][j] is already found out
	return m[i][j];
	
	m[i][j] = INT_MAX;
	for(int k  = i; k <j ; k++)
	{
		m[i][j] = min(m[i][j],buildmatrixChain(p,i,k)+buildmatrixChain(p,k+1,j)+p[i-1]*p[k]*p[j]);
	}
	return m[i][j];
}
int matrixchainMult(int*p, int len)
{
    for(int v = 0; v <= 100; v++)
    for(int o = 0; o <= 100; o++)
    m[v][o] = -1;
	int i = 1, j = len -1;
	return buildmatrixChain(p,i,j);
}


	
	
	
	
