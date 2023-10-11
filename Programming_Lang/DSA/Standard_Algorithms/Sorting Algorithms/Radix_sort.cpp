#include <iostream>
using namespace std;

int max(int ar[],int n)
{
	int mx = ar[0];
	for(int i=0;i<n; i++)
	if(mx < ar[i])
	mx = ar[i];
	return mx;
}

void countsort(int ar[], int n, int exp)
{
	int output[n];
	int count[10] = {0};
	
	for(int i = 0; i < n; i++)
	count[ ar[i]/exp  % 10]++;
	
	//cumulative array tells about the position
	for(int i = 1;i < 10; i++)
	count[i] += count[i-1];
	
	for(int i = n-1; i>=0; i--)
	{
		output[count[ (ar[i]/exp) %10] -1] = ar[i];
		count[ (ar[i] /exp) % 10]--;
	}
	
	//copying the output array to original array
	for(int i = 0; i< n; i++)
	ar[i] = output[i];
	
}

void radixsort(int ar[], int n)
{
	int m = max(ar,n);
	for(int exp = 1; m/exp > 0; exp*=10)
	countsort(ar,n,exp);
	
}




