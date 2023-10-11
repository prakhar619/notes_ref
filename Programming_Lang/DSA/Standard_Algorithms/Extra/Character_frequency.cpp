// string ---------character_frequency-------> string_int_array (2 array, len)


/* Character frequency in ascending Order (of frequency)
 All types of character acceptable
 Edit string_int_array if no of types of character exceed 50
 */


#include <string>
using namespace std;

class string_int_array
{
    public:
	string c[50];
	int freq[50];
	int len;
	
	string_int_array()
	{
		len = 0;
		for(int i = 0; i< 50; i++)
		freq[i] = 0;
	}
};


int partition(string* ar,int* priorty, int low,int high)
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

void quicksort_priorty(string* ar,int* priorty, int low, int high)
{
    if(low < high)
    {
        int par = partition(ar,priorty,low,high);
        quicksort_priorty(ar,priorty,low,par-1);
        quicksort_priorty(ar,priorty,par+1,high);
    }
}

string_int_array character_frequency(string s)
{
	int direct_map[128];
	string_int_array x;
	for(int i = 0; i<128; i++)
	direct_map[i] = -1;
	for(int i = 0; i < s.length(); i++)
	{
		if(direct_map[(int)s[i]] != -1)
		x.freq[direct_map[(int)s[i]]]++;
		else if(direct_map[(int)s[i]] == -1)
		{
			x.c[x.len] = s[i];
			x.freq[x.len]++;
			direct_map[(int)s[i]] = x.len;
			x.len++;
		}
	}
	quicksort_priorty(x.c,x.freq,0,x.len-1);
	return x;
}

