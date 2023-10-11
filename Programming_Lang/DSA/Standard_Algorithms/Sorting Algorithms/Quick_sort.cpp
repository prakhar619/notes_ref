// long long array, 0(start_index of array), length_array ---> sorted array

// swap function used
// unstable sorting

// T(n) = T(k) + T(n-k-1)+O(n)  where k is the no of element less than pivot

// best case : O(nlogn)	  T(n) = 2T(n/2) + O(n)  
//  when pivot is always the middle element  k = n/2


// worst case: O(n^2)
// when pivot is always chosen as smallest or greatest element k= 0,n; T(n) = T(0) + T(n-1) + O(n) => T(n)=  T(n-1) + O(n)

//average case: O(nlogn)
// T(n) = T(n/9) + T(9n/10) + O(n)

// SPACE COMPLEXITY: O(1)

/*
	partition function choses pivot and return array with 2 parts; 1 part is less than pivot and one is greater than pivot;
	partition returns index of pivot;
	partition choses pivot then compare each element in array except itself
	if element is smaller then good;
	if element  is larger than keep its index; and wait for smaller element to appear then swap
	therefore we are searching for smaller element and ordering them for 0 to n using a counter pointer

	therefore quicksort 1st part and 2nd part independently except pivot_index
*/
#include <iostream>
#include <math.h>
using namespace std;

// last element as pivot
long long partition(long long* ar,int low,int high)
{   int j = low;//pointer for larger element
    for(int i= low; i<high;i++)
    {
        if(ar[i]<ar[high]) //CHANGE THE SIGN HERE ONLY TO CONVERT ASC TO DES  //we search for smaller element then swap with already found larger element // last element is the pivot
        {    
            swap(*(ar+i),*(ar+j));// swap every time you find new smaller element
           j++;    //also increase j when swap is done
        }
    }
    swap(*(ar+j),*(ar+high));//for last swap
    return j;
}

// first element as pivot
int low_partition(int* ar,int low,int high)
{   int j = low+1;//pointer for larger element
    for(int i= low+1; i<=high;i++)
    {
        if(ar[i]<ar[low])  //we search for smaller element then swap with already found larger element // last element is the pivot
        {    
            swap(*(ar+i),*(ar+j));// swap every time you find new smaller element
           j++;    //also increase j when swap is done
        }
    }
    swap(*(ar+(j-1)),*(ar+low));//for last swap
    return j-1;
}


void quicksort(long long* ar, int low, int high)
{
    if(low < high)
    {
        long long par = partition(ar,low,high);
        quicksort(ar,low,par-1);
        quicksort(ar,par+1,high);
    }
}

