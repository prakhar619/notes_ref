// long long array, int length_array --> sorted array
// unstable sorting
// swap used

// best case: O(n^2)
// worst case: O(n^2)
// average case: O(n^2)

/*
	we find the min element index then place that element at start
	then we decrease length of array by one , and increase starting index of array by 1
	then we again min element index in smaller array
	we do this from 0 to size -1 for each position of array.
	s*/
#include <iostream>
#include <math.h>
using namespace std;

int min_element_index(long long* ar, int len)
{
    long long min = ar[0];
    int min_index = 0;
    for(int i = 1; i < len; i++)
    {
        if(ar[i] < min)
        {
            min = ar[i];
            min_index = i;
        }
    }
    return min_index;
}

long long * selectionsort(long long* ar, int len)
{
    for(int i = 0; i< len; i++)
    {
        swap( ar[i] , ar[ min_element_index( (ar+i) , len-i ) + i ] );
    }
    return ar;
}



