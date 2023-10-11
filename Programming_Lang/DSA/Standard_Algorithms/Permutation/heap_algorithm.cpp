#include <utility>
#include <iostream>
using namespace std;


void print_ar(int *ar, int len)
{
	for( int i = 0; i < len; i++)
	cout << ar[i] ;
	cout << endl;
}

void heap_permutation(int *ar, int size,int len)
{
	if(size ==1)
	{
		print_ar(ar,len);
		return;
	}
	
	for(int i = 0; i < size;i++)
	{
		heap_permutation(ar,size-1,len);
		
		if(size % 2 == 1)
			swap(ar[0], ar[size -1]);
		
		else
			swap(ar[i],ar[size-1]);
	}
}
