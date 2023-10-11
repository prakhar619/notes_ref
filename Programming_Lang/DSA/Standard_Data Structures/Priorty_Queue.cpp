// asc_priortyQ_heap				//des_priortyQ_heap

/* Priorty Queue is a array which is heaped according to another array value  
Ans of priorty Queue is a heaped range not sorted;      (value)priorty	:  (6)1:(5)2:(3)4:(4)3:(2)5:(1)6
*/

//Time Complexity:
//CLASS FUNCTION
//	push(value , priorty)					O(log N)
//	pop(index)						O(log N)
//	int empty()						O(1)

//CLASS MAIN FUNCTION
//*	asc_prortyQ_heap()					O(1)
//*	asc_priortyQ_heap(value array, priorty array , len)	O(N)
//	print()							O(N)

//CLASS MAIN FUNCTIONS
//	min_heapify(value array, priorty array, len)		O(log N)
//	build_min_heapify(value array, priorty array, len)	O(N)
//	insert(value,priorty)					O(log N)
//	upchain_min_heapify					O(log N)


#include <iostream>
using namespace std;
class asc_priortyQ_heap
{
	public:
	int *priorty_ar;
	int *value_ar;
	int len;
	int size;
	
	asc_priortyQ_heap()
	{
		priorty_ar = NULL;
		value_ar = NULL;
		len = 0;
		size = 0;
	}
	
	asc_priortyQ_heap(int* value,int* prior,int len)
	{
		priorty_ar = (int*) malloc(sizeof(int)*len);
		value_ar = (int*) malloc(sizeof(int)*len);
		for(int i =0; i< len; i++)
		{
			priorty_ar[i] = prior[i];
			value_ar[i] = value[i];
		}
		this->len = len;
		size = len;
		build_min_heapify(value_ar,priorty_ar,len);
	}
	
	void min_heapify(int* value,int *prior, int len, int index)	
	{
		int left_index = index*2+1;		//index of left child	; assuming indexing start from zero
		int right_index = index*2 + 2;		//index of right child
		
		int smallest_index;
		if(left_index < len && prior[left_index] < prior[index])
			smallest_index = left_index;
		else
			smallest_index =  index;
		if(right_index < len && prior[right_index] < prior[smallest_index])
			smallest_index = right_index;
		if(smallest_index != index)
		{
			swap(prior[index],prior[smallest_index]);
            		swap(value[index],value[smallest_index]);
			min_heapify(value,prior,len, smallest_index);
		}
	}
	
	void build_min_heapify(int*value,int* prior, int len)	
	{
		for(int i = (len/2) -1; i>=0;i--)
			min_heapify(value,prior,len,i);
	}
	
	void upchain_min_heapify(int* value_array,int* pr_array,int len,int index)
	{
		int parent = (index % 2 == 0) ? (index/2) -1 : (index/2) ;
		int left_index = parent*2+1;		//index of left child	; assuming indexing start from zero
		int right_index = parent*2 + 2;	
		
		int smallest_index;
		if(left_index < len && parent >= 0 && pr_array[left_index] < pr_array[parent])
			smallest_index = left_index;
		else
			smallest_index =  parent;
		if(right_index < len && parent >= 0 && pr_array[right_index] < pr_array[smallest_index])
			smallest_index = right_index;
		if(smallest_index != parent)
		{
			swap(pr_array[parent],pr_array[smallest_index]);
			swap(value_array[parent],value_array[smallest_index]);
			if(parent != 0)
            upchain_min_heapify(value_array,pr_array,len,parent);
		}
	}
	
	void insert(int value,int priorty)
	{
		if(size == len)
		{
			size = len*2;
			int* newArray_value = new int(size);
			int* newArray_prior = new int(size);
			for(int i = 0; i < len; i++)
			{
				newArray_value[i] = value_ar[i];
				newArray_prior[i] = priorty_ar[i];
			}
			newArray_value[len] = value;
			newArray_prior[len] = priorty;
			free(value_ar);
			free(priorty_ar);
			value_ar = newArray_value;
			priorty_ar = newArray_prior;
			len++;
		}
		else
		{
			value_ar[len] = value;
			priorty_ar[len] = priorty;
			len++;
		}
		upchain_min_heapify(value_ar,priorty_ar , len, len-1);
	}
	
	void push(int val, int priorty)
	{
		insert(val,priorty);
	}
	
		
	void pop(int pos_index = 0)
	{
		swap(priorty_ar[pos_index],priorty_ar[len-1]);
		swap(value_ar[pos_index],value_ar[len-1]);
		len--;
		min_heapify(value_ar,priorty_ar,len,pos_index);
	}
	
	void print()
	{
	    for(int i = 0; i< len-1; i++)
	    {
	        cout << "(" << value_ar[i] << ")"<< priorty_ar[i] << ":" ;
	    }
	        cout << "(" << value_ar[len-1] << ")" << priorty_ar[len-1] ;
	    cout << endl;
	}
	
	int empty()
	{
		if(len == 0)
		return 1;
		return 0;
	}

};

#include <iostream>
using namespace std;
class des_priortyQ_heap
{


public:
	int *priorty_ar;
	int *value_ar;
	int len;
	int size;
	
	des_priortyQ_heap()
	{
		priorty_ar = NULL;
		value_ar = NULL;
		len = 0;
		size = 0;
	}
	
	des_priortyQ_heap(int* value,int* prior,int len)
	{
		priorty_ar = (int*) malloc(sizeof(int)*len);
		value_ar = (int*) malloc(sizeof(int)*len);
		for(int i =0; i< len; i++)
		{
			priorty_ar[i] = prior[i];
			value_ar[i] = value[i];
		}
		this->len = len;
		size = len;
		build_max_heapify(value_ar,priorty_ar,len);
	}
	
	void max_heapify(int*array_val, int* array_prior, int len, int index)	
	{
		int left_index = index*2+1;		//index of left child	; assuming indexing start from zero
		int right_index = index*2 + 2;		//index of right child
		
		int largest_index;
		if(left_index < len && array_prior[left_index] > array_prior[index])
			largest_index = left_index;
		else
			largest_index =  index;
		if(right_index < len && array_prior[right_index] > array_prior[largest_index])
			largest_index = right_index;
		if(largest_index != index)
		{
			swap(array_prior[index],array_prior[largest_index]);
			swap(array_val[index],array_val[largest_index]);
			max_heapify(array_val,array_prior,len, largest_index);
		}
	}
	
	void build_max_heapify(int*value,int* prior, int len)	
	{
		for(int i = (len/2) -1; i>=0;i--)
			max_heapify(value,prior,len,i);
	}
	
	void upchain_max_heapify(int* value_array,int* priorty_array,int len, int index)
	{
		int parent = (index%2 == 0) ? (index/2 -1) : (index/2);
		int largest_index;
		if(index > 0 && priorty_array[parent] < priorty_array[index])
			largest_index = index;
		else
			largest_index = parent;
		if(largest_index != parent)
		{
			swap(priorty_array[index], priorty_array[parent]);
			swap(value_array[index],value_array[parent]);
			upchain_max_heapify(value_array,priorty_array,len,parent);
		}
	}	
	
	void insert(int value,int priorty)
	{
	    cout << priorty << endl;
		if(size == len)
		{
			size = len*2;
			int* newArray_value = new int(size);
			int* newArray_prior = new int(size);
			for(int i = 0; i < len; i++)
			{
				newArray_value[i] = value_ar[i];
				newArray_prior[i] = priorty_ar[i];
			}
			newArray_value[len] = value;
			newArray_prior[len] = priorty;
			free(value_ar);
			free(priorty_ar);
			value_ar = newArray_value;
			priorty_ar = newArray_prior;
			len++;
		}
		else
		{
			value_ar[len] = value;
			priorty_ar[len] = priorty;
			len++;
		}
		upchain_max_heapify(value_ar,priorty_ar , len, len-1);
	}
	
	void push(int val, int priorty)
	{
		insert(val,priorty);
	}
	
		
	void pop(int pos_index = 0)
	{
		swap(priorty_ar[pos_index],priorty_ar[len-1]);
		swap(value_ar[pos_index],value_ar[len-1]);
		len--;
		max_heapify(value_ar,priorty_ar,len,pos_index);
	}
	
	void print()
	{
	    for(int i = 0; i< len-1; i++)
	    {
	        cout << "(" << value_ar[i] << ")"<< priorty_ar[i] << ":" ;
	    }
	        cout << "(" << value_ar[len-1] << ")" << priorty_ar[len-1] ;
	    cout << endl;
	}
	
	int empty()
	{
		if(len == 0)
		return 1;
		return 0;
	}


};
