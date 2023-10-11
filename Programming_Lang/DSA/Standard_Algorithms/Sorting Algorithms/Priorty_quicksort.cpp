// Sorting one array based on values of 2nd array
// both arrays are sorted based on data of 2nd array

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
