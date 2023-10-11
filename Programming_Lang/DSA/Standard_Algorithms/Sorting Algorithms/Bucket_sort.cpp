#include <iostream> 
#include <math.h>

using namespace std;  
  
int getMax(int a[], int n) // function to get maximum element from the given array  
{  
  int max = a[0];  
  for (int i = 1; i < n; i++)  
    if (a[i] > max)  
      max = a[i]; 
  return max;  
}  
void bucketsort(int a[], int n) // function to implement bucket sort  
{  
  int max = getMax(a, n); //max is the maximum element of array  
  int bucket[max];  
  for (int i = 0; i <= max; i++)  //creating empty buckets
  {  
    bucket[i] = 0;  
  }  
  for (int i = 0; i < n; i++)  //increasing value of bucket by one for each specific element
  {  
    bucket[a[i]]++;  
  }  
  for (int i = 0, j = 0; i <= max; i++)  
  {  
    while (bucket[i] > 0)  
    {  
      a[j++] = i;  
      bucket[i]--;  
    }  
  }  
} 


