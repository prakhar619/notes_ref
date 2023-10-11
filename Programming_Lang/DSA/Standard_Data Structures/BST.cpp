//Everything checked; fill time complexity;Also complication at same priorty


// Binary Search Tree
/* left < root < right

2 BST with same data different structure (Balancing is done is variants of BST like R&B Tree and AVL Tree
		5							2
	3		7							3
    2      5	  	   8								7
										     5     8
										   5
*/


//Time Complexity:	N nodes and h height	(here h and n do not have relation)	
//  class bst xxx
//CLASS FUNCTIONS   
//		node* search(key):		O(h)
//		node* insert(value,priorty):	O(h)
//		delete(node*)			O(h)
//		int minimum_bst()		O(h)
//		int maximum_bst()		O(h)
//		node* successor(node*)		O(h)
//		node* predecessor(node*)	O(h)
//		int height(node*)		
//		int height_tree()
//		int depth(node*)


//CLASS WORKING FUNCTIONS
//*		node()					O(1)
//*		node(left, value, priorty, right)	O(1)
// 		inOrderTrav()				O(N)
//		postOrderTrav()				O(N)
//		preOrderTrav()				O(N)
//		dev_preOrderTrav(node*)			O(N)		
//		print_graph()

//CLASS MAIN FUNCTIONS
//		search_main(key, node):					O(h)
//		insert_main(value, key, node, parent node = NULL): 	O(h)
//		inOrderTrav_main(node*):				O(N)
//		postOrderTrav_main(node*):				O(N)
//		preOrderTrav_main(node*):				O(N)
//		node* maximum(node*)					O(h)
//		node* minimum(node*)					O(h)
//		int max( int, int)
//		graphical_rep(node* , max_height)


#include <iostream>
using namespace std;
class node
{
    public:
	int value;
	int priorty;
	node* left;
	node* parent;
	node*right;
	
	node(int value, int priorty, node* left, node* parent, node* right)
	{
		this->left = left;
		this->right = right;
		this->value = value;
		this->priorty = priorty;
		this->parent = parent;
	}
	
	node()
	{
		left = NULL;
		right = NULL;
		value = 0;
		priorty = 0;
		parent = NULL;
	}
};

class bst
{
    public:
	node* root = NULL;
	
	node* search_main(int key, node* NNode)
	{
	    if(NNode == NULL)
	    {
	       	cout << "NOT FOUND" << endl;
	       	node* not_node;
			return not_node;
	    }
		else if(NNode->priorty == key)
		{
			return NNode;
		}
		
		if(key > NNode->priorty)
		return search_main(key,NNode->right);
		else
		return search_main(key,NNode->left);
	}
	
	node* search(int key)
	{
		return search_main(key,root);
	}
	
	// always added as leaf node
	// *** editing NNode after it is NULL does not change its value up the chain therefore parent needed;
	// THerefore be carefull;
	node* insert_main(int value, int priorty,node* NNode,node* parent = NULL)
	{
		if(NNode == NULL)
		{
			node* newNode = new node(value,priorty,NULL,parent,NULL);
			if(priorty < parent->priorty)
			{
				parent->left = newNode;
				newNode->parent = parent;
			}
			else
			{
				parent->right = newNode;
				newNode->parent = parent;
			}
			return newNode;
		}
		if(priorty > NNode->priorty)
		return insert_main(value,priorty,NNode->right,NNode);
		else
		return insert_main(value,priorty,NNode->left,NNode);
		
	
	}
	
	node* insert(int value,int priorty)
	{
	    if(root == NULL)
	    {
	    node* newNode = new node(value,priorty,NULL,NULL,NULL);
		root = newNode;
		return root;
	    }
		return insert_main(value,priorty,root);
	}
	
	void preOrderTrav_main(node* NNode)
	{
	    if(NNode == NULL)
	    return;
	    cout << "(" <<NNode->value << ")" << NNode->priorty << ":";
	    preOrderTrav_main(NNode->left);
	    preOrderTrav_main(NNode->right);
	}
	void preOrderTrav()
	{
	    preOrderTrav_main(root);
	    cout << endl;
	}
	void inOrderTrav_main(node* NNode)
	{
	    if(NNode == NULL)
	    return;
	    inOrderTrav_main(NNode->left);
	    cout << "(" <<NNode->value << ")" << NNode->priorty << ":";
	    inOrderTrav_main(NNode->right);
	}
	void inOrderTrav()
	{
	    inOrderTrav_main(root);
	    cout << endl;
	}
	void postOrderTrav_main(node* NNode)
	{
	    if(NNode == NULL)
	    return;
	    postOrderTrav_main(NNode->left);
	    postOrderTrav_main(NNode->right);
	    cout << "(" <<NNode->value << ")" << NNode->priorty << ":";
	}
	void postOrderTrav()
	{
	    postOrderTrav_main(root);
	    cout << endl;
	}
	
	
	node* maximum(node* NNode)
	{
		if(NNode->right == NULL)
		return NNode;
		
		return maximum(NNode->right);
	}
	
	int maximum_bst()
	{
	    return maximum(root)->priorty;
	}
	
	node* minimum(node* NNode)
	{
		if(NNode->left == NULL)
		return NNode;
		
		return minimum(NNode->left);
	}
	
	int minimum_bst()
	{
	    return minimum(root)->priorty;
	}
	
	// successor of node x is lowest value node with value greater than x->value;
	//case 1: node->right->left->left->....
	//case 2: node->right == NULL  		node->parent[node]->parent[parent[node]]->till parent is right child of a its parent; stop is parent with left child
	/* case 2 example
					15
			6				18
		3		7		17		20
	     2	   4	           13
	     			  9
	     successor(13) = 15
	*/
	// just jadi value
	node* successor(node* NNode)
	{
		if(NNode->right != NULL)
		return minimum(NNode->right);

		else
		{ 
			node* y = NNode->parent;
			while( y != NULL && y->right == NNode)
			{
				NNode = y;
				y = NNode->parent;
			}
			return y;
		}
	}
	
	//just choti value
	node* predecessor(node* NNode)
	{	
		if(NNode->left != NULL)
		return maximum(NNode->left);
		else
		{
			node* y = NNode->parent;
			while( y != NULL && y->left == NNode)
			{
				NNode=  y;
				y = NNode->parent;
			}
			return y;
		}
	}
	// case 1: node is a leaf node============= free + parent adjust NULL
	// case 2: node has single child=========== free + child link with grandparent			10 - x - 20	=>   10 - 20
	// case 3: node has both child============= successor(node) replaces node + recursion(remove node successor(original pos))
	void delete_node(node* NNode)
	{
		if(NNode->left == NULL && NNode->right == NULL)
		{
			if(NNode->parent->priorty  > NNode->priorty)
			NNode->parent->left = NULL;
			else
			NNode->parent->right = NULL;
			free(NNode);
		}
		
		else if(NNode->left == NULL && NNode->right != NULL)
		{
			if(NNode->parent->priorty > NNode->priorty)
			NNode->parent->left = NNode->right;
			else
			NNode->parent->right = NNode->right;
			free(NNode);
		}
		else if(NNode->left != NULL && NNode->right == NULL)
		{
			if(NNode->parent->priorty > NNode->priorty)
			NNode->parent->left = NNode->left;
			else
			NNode->parent->right = NNode->left;
			free(NNode);
		}
		
		else if(NNode->left != NULL && NNode->right != NULL)
		{
			node* sucr = successor(NNode);
			NNode->value = sucr->value;
			NNode->priorty = sucr->priorty;
			delete_node(sucr);
		}
			
			
	}
	
	void dev_preOrderTrav(node* NNode)
	{
	   if(NNode == NULL)
	   {    
	       cout << "NULL" << ":";
	       return;
	   }
	   	cout << NNode->priorty << ":";
	    dev_preOrderTrav(NNode->left);
	    dev_preOrderTrav(NNode->right);
	}
	
	
	
	
	
	int max(int x,int y)
	{
		if(x > y)
		return x;
		return y;
	}
	
	int height(node* NNode)
	{
		int height_n;
		if(NNode == NULL)
		return height_n = 0;
		height_n = max(height(NNode->left) + 1,height(NNode->right) + 1);
		return height_n;
	}
	
	int height_tree()
	{
		return height(root);
	}
	
	int depth(node* NNode,int initial_depth = 1)
	{
		if(root == NNode)
		{	
			
			return initial_depth;
		}
		int dep = depth(NNode->parent,initial_depth);
		return dep+1;
	}
	
	void graphical_rep(node* NNode,int max_height)
	{
		if(NNode == NULL)
	    	return;
	    graphical_rep(NNode->left,max_height);
	    int depth_n = depth(NNode);
	    while(max_height != depth_n)
	    {
    		cout << "	";
    		depth_n++;
    	    } 
	    cout <<"(" <<NNode->value << ")" << NNode->priorty << ":" << endl;
	    graphical_rep(NNode->right,max_height);
	}

	void print_graph()
	{
		graphical_rep(root,height_tree());
		return;
	}
	
		
};

/*
#include <iomanip>
int main() {
    bst tree;
    int j = 0;
    int flg = 33;
    node* delete_this_node;
    for(int i = 0; i < 45; i++)
    {
    	int priorty = (i*j)%91 + i;
    	if((i) == flg)
    	{
    		delete_this_node = tree.insert(i,priorty);
    		cout << setw(25) << left <<"Inserting Element No:" << setw(10) <<left << i << setw(10)<<left << "Value:" << setw(10) << left<< i << setw(10)<<left << "Priorty:" << setw(10) << left << priorty << endl;
    	}
    	else
    	{
    		tree.insert(i,priorty);
    		cout << setw(25) << left <<"Inserting Element No:" << setw(10) <<left << i << setw(10)<<left << "Value:" << setw(10) << left<< i << setw(10)<<left << "Priorty:" << setw(10) << left << priorty << endl;
    	}
    	j = i*7- j;
    }
    cout << "Tree Height:" << tree.height_tree() << endl;
    cout << "Minimum:" << tree.minimum_bst() << endl;
    cout << "Maximum:" << tree.maximum_bst() << endl;
    cout << "Search for Node with Value:" << 10 <<"=>"<< tree.search(10) << endl;
    cout << "Node Info"<<endl;
    cout << "Node Address:" << delete_this_node << endl;
    cout << "Node Priorty:" << delete_this_node->priorty << endl;
    cout << "Node Value:" << delete_this_node->value << endl;
    cout << "Node Height:" << tree.height(delete_this_node) << endl;
    cout << "Node Depth:" << tree.depth(delete_this_node) << endl;
    cout << "Node Successor:" << tree.successor(delete_this_node) << " Value:" << tree.successor(delete_this_node)->value << " Priorty:" <<tree.successor(delete_this_node)->priorty << endl; 
    cout << "Node Predecessor:" << tree.predecessor(delete_this_node) << " Value:" << tree.predecessor(delete_this_node)->value << " Priorty:" <<tree.predecessor(delete_this_node)->priorty << endl; 
    cout << "Deleting Node:" << delete_this_node << endl;
    tree.delete_node(delete_this_node);
    cout << endl;
    tree.print_graph();
    return 0;
}
*/

