// Data Structure  Priorty Queue Node Based;
// 2 array (1 value)(1 priorty) --------creates nodes-----> Priorty Queue of Nodes
// insert(value,priorty)	--------creates node----->Priorty Queue of Nodes

// Instead of using 2 array (one value and one one priorty) 
// We are using array of Node
//Priorty is based on node->freq



//Time Complexity:
//CLASS FUNCTION
//	push(value , priorty)					O(log N)
//	pop(index)						O(log N)
//	int empty()						O(1)
//	node* peek()						O(1)

//CLASS MAIN FUNCTION
//*	asc_prortyQ_heap()					O(1)
//*	asc_priortyQ_heap(value array, priorty array , len)	O(N)
//	print()							O(N)

//CLASS MAIN FUNCTIONS
//	min_heapify(value array, priorty array, len)		O(log N)
//	build_min_heapify(value array, priorty array, len)	O(N)
//	insert(value,priorty)					O(log N)
//	upchain_min_heapify					O(log N)

#include <string>
#include <iostream>
using namespace std;
class node
{
    public:
	int freq;
	string c;
	bool leaf;
	node* left;
	node* right;
	
	node()
	{
		freq = 0;
		c = "";
		left = NULL;
		right = NULL;
		leaf = 0;
	}
	node(int f,node* left, node* right )
	{
		freq = f;
		this->left = left;
		this->right=  right;
		c = "";
		leaf= 0;
	}
	node(int f, string s)
	{
		freq = f;
		c = s;
		left = NULL;
		right = NULL;
		leaf = 1;
	}
};

class asc_priortyQ_heap
{
	public:
	node** NodeArray;	
	int len;
	int size;
	
	asc_priortyQ_heap()
	{
		len = 0;
		size = 0;
	}
	
	asc_priortyQ_heap(string* value,int* prior,int len)
	{
		node** NodeArray1 = new node*[len];
		NodeArray = NodeArray1;
		for(int i =0; i< len; i++)
		{
			node* newNode = new node(prior[i],value[i]);
			NodeArray[i] = newNode;
		}
		this->len = len;
		size = len;
		build_min_heapify(NodeArray,len);
	}
	
	void swap (node* &a,node* &b)
	{
		node* c = a;
		a = b;
		b = c;
	}
	
	void min_heapify(node* NodeArray[], int len, int index)	
	{
		int left_index = index*2+1;		//index of left child	; assuming indexing start from zero
		int right_index = index*2 + 2;		//index of right child
		
		int smallest_index;
		if(left_index < len && NodeArray[left_index]->freq < NodeArray[index]->freq)
			smallest_index = left_index;
		else
			smallest_index =  index;
		if(right_index < len && NodeArray[right_index]->freq < NodeArray[smallest_index]->freq)
			smallest_index = right_index;
		if(smallest_index != index)
		{
			swap(NodeArray[index],NodeArray[smallest_index]);
			min_heapify(NodeArray,len, smallest_index);
		}
	}
	
	void build_min_heapify(node* NodeArray[], int len)	
	{
		for(int i = (len/2) -1; i>=0;i--)
			min_heapify(NodeArray,len,i);
	}
	
	void upchain_min_heapify(node* NodeArray[],int len,int index)
	{
		int parent = (index % 2 == 0) ? (index/2) -1 : (index/2) ;
		int left_index = parent*2+1;		//index of left child	; assuming indexing start from zero
		int right_index = parent*2 + 2;	
		
		int smallest_index;
		if(left_index < len && parent >= 0 && NodeArray[left_index]->freq < NodeArray[parent]->freq)
			smallest_index = left_index;
		else
			smallest_index =  parent;
		if(right_index < len && parent >= 0 && NodeArray[right_index]->freq < NodeArray[smallest_index]->freq)
			smallest_index = right_index;
		if(smallest_index != parent)
		{
			swap(NodeArray[parent],NodeArray[smallest_index]);
			if(parent != 0)
            upchain_min_heapify(NodeArray,len,parent);
		}
	}
	
	void insert(node* newNode)
	{
		if(size == len)
		{
			size = len*2;
			node** newArray_= new node*[size];
			for(int i = 0; i < len; i++)
			{
				newArray_[i] = NodeArray[i];
			}
			newArray_[len] = newNode;
			free(NodeArray);
			NodeArray = newArray_;
			len++;
		}
		else
		{
			NodeArray[len] = newNode;
			len++;
		}
		upchain_min_heapify(NodeArray, len, len-1);
	}
	
	void push(node* newNode)
	{
		insert(newNode);
	}
	
	node* peek()
	{
	    return NodeArray[0];
	}
		
	void pop(int pos_index = 0)
	{
		swap(NodeArray[pos_index],NodeArray[len-1]);
		len--;
		min_heapify(NodeArray,len,pos_index);
	}
	
	void print()
	{
	    for(int i = 0; i< len-1; i++)
	    {
	        cout << "(" << NodeArray[i]->c << ")"<< NodeArray[i]->freq << ":" ;
	    }
	    	cout << "(" << NodeArray[len-1]->c << ")"<< NodeArray[len-1]->freq ;
	    cout << endl;
	}
	
	int empty()
	{
		if(len == 0)
		return 1;
		return 0;
	}
	
	void dev_preOrderTrav(node* NNode)
{
	   if(NNode == NULL)
	   {    
	       cout << "NULL" << ":";
	       return;
	   }
	   	cout << "(" << NNode->c <<")" << NNode->freq << ":";
	    dev_preOrderTrav(NNode->left);
	    dev_preOrderTrav(NNode->right);
}

};
