// int array , int length_array --> sorted array

// unstable sort
// similar to selection sort but uses heap data structure

// best case: O(nlogn)
// worst case: 
// average case:

/*
	build_max_heap 	--uses max heapify
		max heapify
			it assumes binary tree with given index is not a heap but its children (both) are max heap; therefore only one wrong position
			so we need to find the largest among those 3 element (root and two child element)
			and then swap it with root(or given index)
			after swapping it might be that that child tree is not heap anymore
			therefore sub problem same as parent problem.
			Therefore recursion with child index
		
	to build max heap we need to start max heap with last subtree. Index of root of smallest tree len/2 -1 
	max heap it then decrease index by 1 then max heap, go on till index = 0
	
	
to sort array build max_heap then 1s element is the largest element therefore swap it with last element
then max_heap to build heap but decrease array size by 1
then again swap 1st element(second largest) with second last element
...

		
*/

#include <iostream>
using namespace std;
void swap( int& a, int&b)
{
	int dup = a;
	a = b;
	b= dup;
}

void max_heapify(int ar[], int len, int index)	//array and index; assumes that binary tree left and right of index i are max heap but A[i] might be smaller than its left or right
{
	int left_index = index*2 + 1;
	int right_index = index*2 + 2;
	
	int largest_index;
	if( left_index < len && ar[left_index] > ar[index])
	largest_index = left_index;
	else
	largest_index =  index;
	if( right_index < len && ar[right_index] > ar[largest_index])
	largest_index = right_index;
	if(largest_index != index)
	{
		swap(ar[index],ar[largest_index]);
		max_heapify(ar,len, largest_index);
	}
		
}

// optional 
void min_heapify(int ar[], int len, int index)
{
	int left_index = index*2 + 1;
	int right_index = index*2 + 2;
	
	int min_index;
	if( left_index < len && ar[left_index] < ar[index])
	min_index = left_index;
	else
	min_index =  index;
	if( right_index < len && ar[right_index] < ar[min_index])
	min_index = right_index;
	if(min_index != index)
	{
		swap(ar[index],ar[min_index]);
		min_heapify(ar,len,min_index);
	}
}

void build_max_heap(int ar[], int len)
{	
	for(int i = (len/2) -1; i>= 0; i--)
	{
		max_heapify(ar,len,i);
	}
}



void heapsort(int ar[], int len)
{
	build_max_heap(ar,len);
	for(int i = len -1 ; i>=1; i--)
	{   
		swap(ar[0],ar[i]);
		max_heapify(ar,i,0);
		cout << endl;
	}
}


