//Segment tree implementation

#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    int start;
    int end;
    Node* left;
    Node* right;
    
    Node(int val,int start, int end)
    {
        this->val = val;
        this->start = start;
        this->end = end;
        this->left = NULL;
        this->right= NULL;
    }
    Node(Node* left, int val, Node* right,int start , int end)
    {
        this->val =val;
        this->left = left;
        this->right = right;
        this->start = start;
        this->end= end;
    }
};
class segmentTree{
    public:  
    Node* root;
    int ar_size;
    Node* array_initialisation(int arr[], int start, int end)
    {
        if(start == end)
        {
            Node* new_Leafnode = new Node(arr[start],start, end);
            return new_Leafnode;
        }
        if(start > end)
        {
            return NULL;
        }
        int middle = start + (end - start)/2;
        Node* new_node = new Node(array_initialisation(arr,start,middle),0,array_initialisation(arr,middle+1,end),start,end);
        new_node->val = new_node->left->val + new_node->right->val;
        return new_node;
    }

    segmentTree(int arr[],int size)
    {
        root = array_initialisation(arr,0,size-1);
        ar_size = size;
    }

    Node* Node_update(Node* NNode,int index, int val,int start,int end)
    {
        if(start == end)
        {
            NNode->val = val;
            return NNode;
        }
        if(start > end)
        {
            return NULL;
        }

        int mid = (start + end)/2;
        if(index <= mid)
        {
            NNode->left = Node_update(NNode->left,index,val,start,mid);
            NNode->val = NNode->left->val + NNode->right->val;
            return NNode;
        }
        else{
            NNode->right = Node_update(NNode->right,index,val,mid+1,end);
            NNode->val = NNode->left->val + NNode->right->val;
            return NNode;
        }
    }

    void update(int index, int val)
    {
        root = Node_update(root,index,val,0,ar_size-1);
    }

    int Node_sum(Node* NNode,int given_start , int given_end)
    {
        if( (given_start == NNode->start) && (given_end == NNode->end))
        return NNode->val;

        int mid = (NNode->start + NNode->end)/2;
        if(given_start <= mid && given_end <= mid)
        {
            return Node_sum(NNode->left,given_start,given_end);
        }
        else if(given_start > mid && given_end > mid)
        {
            return Node_sum(NNode->right,given_start,given_end);
        }
        else
        {
            return Node_sum(NNode->left,given_start,mid) + Node_sum(NNode->right,mid+1,given_end);
        }
    }
    
    int sum(int start,int end)
    {
        return Node_sum(root,start,end);
    }
        

    void dev_preOrderTrav(Node* NNode)
	{
	   if(NNode == NULL)
	   {    
	       cout << "NULL" << ":";
	       return;
	   }
	   	cout << NNode->val << ":";
	    dev_preOrderTrav(NNode->left);
	    dev_preOrderTrav(NNode->right);
	}
};



int main()
{
    int arr[] = {0,-3,-3,1,1,2};
    int size = 6;
    segmentTree* t = new segmentTree(arr,size); 
    t->dev_preOrderTrav(t->root);
    cout << "\n" << endl;
    //nc[yotj]t->update(4,5);
    t->dev_preOrderTrav(t->root);

    cout << endl;
    cout << t->Node_sum(t->root,2,4);
}

