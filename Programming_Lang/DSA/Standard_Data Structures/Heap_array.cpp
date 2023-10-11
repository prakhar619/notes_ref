// maxheap				//minheap

/*Data structure HEAP (Heap is not sorted)
Although heap is usually thought as binary tree, implementation uses heap as array;   Array can represent ONLY COMPLETE BINARY TREE (complete binary tree means all lvl filled + as left as possible)								
					10
				9		7
			3 	     4	  5		6
	       1	  2								Output: [10,9,7,3,4,5,6,1,2]	A heap (max)   
*/

/* Heap 	Althought this is a heap it cannot be represent using array switch to BST version.
				10
			9		7	
				      2	  3
				     1	   0
*/



//Time complexity: 
//CLASS FUNCTIONS	
//			pop(index=0)		O(logN)
//			insert(value)	  	O(logN)
//			int peek()		O(1)

//CLASS WORKING FUNCTIONS
//			print()			O(N)
//*			maxheap()		O(1)
//*			maxheap(array,len)	O(N)

//CLASS MAIN FUNCTIONS
//			swap(a,b)				O(1)
//			max_heapify(array,len,index)   		O(logN)
//			upchain_max_heapify(array,len,index)	O(logN)
//			build_max_heapify(array,len) 		O(NlogN)

		
#include <iostream>
using namespace std;
class maxheap
{
	public:
	int* array;
	int len;
	int size;
	
	//constructors
	maxheap()
	{
	 	len = 0;
	 	array = NULL;
	 	size = 0;
	}
	maxheap(int *ar, int len)		
	{
		array = (int*) malloc(sizeof(int)*len);
		for(int i = 0; i< len; i++)
		{
			array[i] = ar[i];
		}
		this->len = len;
		size = len;
		build_max_heapify(array,this->len);
	}
	
	//helping functions
	void swap (int &a,int &b)
	{
	    int k = a;
	    a = b;
	    b = k;
	}
			// assumes that root(index) and its children are not in heap; but children tree are in heap
	void max_heapify(int* ar, int len, int index)	
	{
		int left_index = index*2+1;		//index of left child	; assuming indexing start from zero
		int right_index = index*2 + 2;		//index of right child
		
		int largest_index;
		if(left_index < len && ar[left_index] > ar[index])
			largest_index = left_index;
		else
			largest_index =  index;
		if(right_index < len && ar[right_index] > ar[largest_index])
			largest_index = right_index;
		if(largest_index != index)
		{
			swap(ar[index],ar[largest_index]);
            
			max_heapify(ar,len, largest_index);
		}
	}
	
	void build_max_heapify(int *ar, int len)	
	{
		for(int i = (len/2) -1; i>=0;i--)
			max_heapify(ar,len,i);
	}
	
	void upchain_max_heapify(int *ar,int len, int index)
	{
		int parent = (index%2 == 0) ? (index/2 -1) : (index/2);
		int largest_index;
		if(index > 0 && ar[parent] < ar[index])
			largest_index = index;
		else
			largest_index = parent;
		if(largest_index != parent)
		{
			swap(ar[index], ar[parent]);
			if(parent != 0)
			upchain_max_heapify(ar,len,parent);
		}
	}
	
	//heap operations
	void insert(int value)
	{
		if(size == len)
		{
			size = len*2;
			int* newArray = new int(size);
			for(int i = 0; i < len; i++)
				newArray[i] = array[i];
			newArray[len] = value;
			free(array);
			array = newArray;
			len++;
		}
		else
		{
			array[len] = value;
			len++;
		}
		upchain_max_heapify(array , len, len-1);
	}
	void print()
	{
	       for( int i = 0; i < len-1; i++)
	       cout << array[i]<< ":";
	       cout << array[len-1] << endl;
	}
	void pop(int pos_index = 0)
	{
		swap(array[len-1], array[pos_index]);
		len--;
		max_heapify(array,len,pos_index);
	}	
	int peek()
	{
		return array[0];
	}

};



//Time complexity: 
//CLASS FUNCTIONS	
//			pop(index=0)		O(logN)
//			insert(value)	  	O(logN)
//			int peek()		O(1)

//CLASS WORKING FUNCTIONS
//			print()			O(N)
//*			minheap()		O(1)
//*			minheap(array,len)	O(N)

//CLASS MAIN FUNCTIONS
//			swap(a,b)				O(1)
//			min_heapify(array,len,index)   		O(logN)
//			upchain_min_heapify(array,len,index)	O(logN)
//			build_min_heapify(array,len) 		O(N)

#include <iostream>
using namespace std;
class minheap
{
	public:
	int* array;
	int len;
	int size;
	
	//constructors
	minheap()
	{
	 	len = 0;
	 	size = 0;
	 	array = NULL;
	}
	minheap(int *ar, int len)		
	{
		array = (int*)malloc(sizeof(int)*len);
		for(int i = 0; i < len; i++)
		    array[i] = ar[i];
		this->len = len;
		size = len;
		build_min_heapify(array,this->len);
	}
	
	
	//helping functions
	void swap (int &a,int &b)
	{
	    int k = a;
	    a = b;
	    b = k;
	}
	
	void min_heapify(int* ar, int len, int index)	
	{
		int left_index = index*2+1;		//index of left child	; assuming indexing start from zero
		int right_index = index*2 + 2;		//index of right child
		
		int smallest_index;
		if(left_index < len && ar[left_index] < ar[index])
			smallest_index = left_index;
		else
			smallest_index =  index;
		if(right_index < len && ar[right_index] < ar[smallest_index])
			smallest_index = right_index;
		if(smallest_index != index)
		{
			swap(ar[index],ar[smallest_index]);
            
			min_heapify(ar,len, smallest_index);
		}
	}
	
	void upchain_min_heapify(int *ar,int len,int index)
	{
		int parent = (index % 2 == 0) ? (index/2) -1 : (index/2) ;
		int left_index = parent*2+1;		//index of left child	; assuming indexing start from zero
		int right_index = parent*2 + 2;	
		
		int smallest_index;
		if(left_index < len && parent >= 0 && ar[left_index] < ar[parent])
			smallest_index = left_index;
		else
			smallest_index =  parent;
		if(right_index < len && parent >= 0 && ar[right_index] < ar[smallest_index])
			smallest_index = right_index;
		if(smallest_index != parent)
		{
			swap(ar[parent],ar[smallest_index]);
			if(parent != 0)
            upchain_min_heapify(ar,len,parent);
		}
	}
	
	void build_min_heapify(int *ar, int len)	
	{
		for(int i = (len/2) -1; i>=0;i--)
			min_heapify(ar,len,i);
	}
	
	void insert(int value)
	{
		if(size == len)
		{
			size = len*2;
			int* newArray = new int(size);
			for(int i = 0; i < len; i++)
				newArray[i] = array[i];
			newArray[len] = value;
            free(array);
			array = newArray;
			len++;
		}
		else
		{
			array[len] = value;
			len++;
		}
        upchain_min_heapify(array, len,len-1);
	}
	
	void pop(int pos_index = 0)
	{
			swap(array[pos_index],array[len-1]);
			len--;
			min_heapify(array,len,pos_index);
	}
	
	int peek()
	{
	    return array[0];
	}
	
	void print()
	{
	       for( int i = 0; i < len-1; i++)
	       cout << array[i]<< ":";
	       cout << array[len-1] << endl;
	}
};

