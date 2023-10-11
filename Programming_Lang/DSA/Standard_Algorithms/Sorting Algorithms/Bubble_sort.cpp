// long long array, int length_of_array --> sorted array

// swap function used

//  best case O(n^2), but zero swaps
//  array is already sorted

//  worst case O(n^2), n(n-1)/2 swaps, 
//  array is in opposite sorted order

//  average case O(n^2), 

// SPACE COMPLEXITY: O(1)

/*  Starting from zero index, swapping n, n+1 element to place them in order
    then n+1, n+2 element to get them in order, 
    After one iteration of outer loop, largest element is at last, rest are not ordered
    Therefore we have now array of new size (new_size = old_size -1)
    each outer iteration decrease new array size by one
*/

#include <iostream>
#include <math.h>
using namespace std;

long long* bubblesort(long long* ar, int len)
{
    for(int i = 0; i < len -1 -i ; i++)
        for(int j = 0; j <len -1; j++)
            if(ar[j] > ar[j+1])
                swap(ar[j],ar[j+1]);
    return ar;
}





