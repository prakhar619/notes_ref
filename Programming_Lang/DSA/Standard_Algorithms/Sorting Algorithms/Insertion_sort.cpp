// long long array, int length_array ---> sorted array
// 
// best case: O(n)
// already sorted array

// worst case: O(n^2)
// opposited sorted array

// average case: O(n^2)

// Time Complexity: O(1)

/* Its places each element in correct position with respect to elements before it.
	23, 34, 56, 65, 67, 1, 45
	like when index is on 1, 1 will be compared with each element before to find element lesser element than
	it to place 1 after it.
	Before 1, every element will already be sorted
*/

#include <iostream>
using namespace std;

long long* insertionsort(long long* ar, int len)
{
    for(int i = 1; i<len; i++)
    {   
        int j = i;
        long long temp = ar[j];
        while(ar[j-1] > temp && j>0)
        {
            ar[j] = ar[j-1];
            j-=1;
        }
        ar[j] = temp;
    }
    return ar;
}

