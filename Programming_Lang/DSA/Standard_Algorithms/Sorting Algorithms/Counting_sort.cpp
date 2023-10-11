#include <iostream>
using namespace std;

int getMax(int ar[], int n)
{
	int max = ar[0];
	for(int i = 0; i< n; i++)
	if(ar[i] > max)
	max = a[i];
	return max;
}


void countsort( int ar[], int n)
{
	int max = getMax(ar,n);
	int countAr[max];
	for(int i = 0; i <= max; i++)
	countAr[i] = 0;
	for(int i = 0; i < n; i++)
	countAr[ar[i]]++;
	
	int cumulative = 0;
	for(int i = 0; i<=  max; i++)
	{
		cumulative = countAr[i] + cumulative;
		countAr[i] = cumulative;
	}
	
	int newAr[n];
	for(int i = n; i> 0; i--)
	{
		newAr[--countAr[ar[i]]] = ar[i];
	}
	
	for(int i = 0; i< n ; i++)
	ar[i] = newAr[i];
}

int main()
{	
	int ar[] = {1,2,3,41,2,23,56,40,46,7,8,23,4};
	countsort(ar,sizeof(ar)/4);
	for(int i : ar)
	cout << i << endl;
	return 1;
}
