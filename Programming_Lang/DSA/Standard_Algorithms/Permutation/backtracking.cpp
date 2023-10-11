#include <utility>
#include <iostream>
using namespace std;

/* 										ABC

		ABC (0 with 0)						BAC (0 with 1)						CAB (0 with 2)
	
ABC (1 with 1)			ACB(1 with 2)		BAC(1 with 1) 			BCA(1 with 2)		CAB(1 with 1) 			CBA(1 with 2)


*/

void print_ar(int *ar, int len)
{
	for( int i = 0; i < len; i++)
	cout << ar[i] ;
	cout << endl;
}

void permutate(int* ar, int len, int start_index = 0)
{
	if(len-1 == start_index)
		print_ar(ar,len);
	else
	{
		for(int i = start_index; i < len; i++)
		{
			swap(ar[start_index],ar[i]);
			permutate(ar,len,start_index+1);
			
			//backtract
			swap(ar[start_index],ar[i]);
		}
	}
}	
	
