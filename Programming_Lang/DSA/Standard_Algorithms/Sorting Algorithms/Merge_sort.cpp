// long long array, int 0(starting index), int length_array_index ---> sorted array 
// 

// best case scenerio: O(nlogn)		T(n) = T(n/2) + O(n)
// worst case scenerio: O(nlogn)
// average case scenerio: O(nlogn)

// SPACE COMPLEXITY: O(n)

/*
Two function : mergesort and merge
merge takes 1 array, which it takes as 2 sorted array which just need to be merged,
This array passed on merge is divides by mid, therefore left is starting index of 1st array and mid is end of 1st array; mid+1
Merging is an easy process and we need to just take 1st element compare them and order them increment value of original array

mergesort divides array by mid = start + (end - start)/2;   0+ (10-0)/2
Its important to use start when dividing by 2 to get mid element; end/2 will be wrong
Then merge sort the first part and second part 
Then merge the first and second part 
*/

#include <iostream>
using namespace std;

void merge(long long* arr, int left, int mid, int right)
{
    int subArrayOne = mid -left +1; //size of subArray
    int subArrayTwo = right -mid;

    long long leftArray[subArrayOne];// declaring subArray
    long long* rightArray = new long long[subArrayTwo];

    for(int i = 0;i<subArrayOne;i++)    //storing values of subarray
    leftArray[i] = arr[left+i];
    for(int i= 0; i<subArrayTwo;i++)
    rightArray[i] = arr[mid+i+1];
    
    int indexofSubArrayOne = 0;     //starting index of subArray
    int indexofSubArrayTwo = 0; 
    int indexofMergedArray = left;

    while(indexofSubArrayOne < subArrayOne && indexofSubArrayTwo < subArrayTwo) //storing value in original array according to order
    {
        if (leftArray[indexofSubArrayOne] <= rightArray[indexofSubArrayTwo])
        {
            arr[indexofMergedArray] = leftArray[indexofSubArrayOne];
            indexofSubArrayOne++;
        }
        else 
        {
            arr[indexofMergedArray] = rightArray[indexofSubArrayTwo];
            indexofSubArrayTwo++;
        }
        indexofMergedArray++;

    }
     while (indexofSubArrayOne < subArrayOne)   //remaining element
    {
        arr[indexofMergedArray]
            = leftArray[indexofSubArrayOne];
        indexofSubArrayOne++;
        indexofMergedArray++;
    }
    while (indexofSubArrayTwo < subArrayTwo) //remaining element
    {
        arr[indexofMergedArray]
            = rightArray[indexofSubArrayTwo];
        indexofSubArrayTwo++;
        indexofMergedArray++;
    }
    
    delete[] rightArray;
}
void mergesort(long long* arr,int start, int end)
{
    if(start >= end)
    return;

    int mid = start +(end - start) /2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    merge(arr,start,mid,end);
}


