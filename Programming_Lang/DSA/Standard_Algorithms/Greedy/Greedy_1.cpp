//Greedy Algorithm           ACTIVITY SELECTION PROBLEM


/*
Max no of activity a person can select.
E.g.
start[]  =  {1, 3, 0, 5, 8, 5}, finish[] =  {2, 4, 6, 7, 9, 9};
Ans = 0 1 3 4

Method: We are just choosing activities based on finish array. Activity which finishes first is selected first.
Therefore we need to sort both based on finish value (ascending order)
Then we check if start of next activity is greater than end of previous activity.
If yes then add else move to new activity
*/ 

//Time Complexity: O(N)

#include<iostream>
using namespace std;
int partition(int* ar,int* priorty, int low,int high)
{
	 int j = low;//pointer for larger element
    	for(int i= low; i<high;i++)
    	{
        	if(priorty[i]<priorty[high])  //we search for smaller element then swap with already found larger element // last element is the pivot
        	{    
           		swap(*(priorty+i),*(priorty+j));// swap every time you find new smaller element
           		swap(*(ar+i),*(ar+j));
           		j++;    //also increase j when swap is done
        	}
    }
    swap(*(priorty+j),*(priorty+high));
    swap(*(ar+j),*(ar+high));//for last swap
    return j;
}

void quicksort_priorty(int* ar,int* priorty, int low, int high)
{
    if(low < high)
    {
        int par = partition(ar,priorty,low,high);
        quicksort_priorty(ar,priorty,low,par-1);
        quicksort_priorty(ar,priorty,par+1,high);
    }
}


void activity_selection_problem(int* start, int* end, int len)
{
	quicksort_priorty(start,end,0,len-1);
	
	int i,j;
	i = 0;
	cout << i << " ";	//First element always get selected
	
	for(j = 1; j < len ; j++)
	if(start[j] >= end[i])
	{
		cout << j << " ";
		i = j;
	}
}
	
