//Everything checked; fill time complexity;Also complication at same priorty ( R->child = R); delete fucntionality not added;

//Red&Black Tree

/* Properties
1.Every node is either red or black
2.Root is black
3.Leaf is black
4.If a node is red then both children are black           
5.For everypath to leaf node same no of black nodes
*/


/* Result
1. n internal node has height atmost 2log(n+1)
*/
//black_height()


// Red and Black Tree
/* left < root < right and black height defined;

2 BST with same data different structure (Balancing is done is variants of BST like R&B Tree and AVL Tree
		5							2
	3		7							3
    2      5	  	   8								7
										     5     8
		    								   5
*/


//Time Complexity:	N nodes and h height	(here h and n do not have relation)	
//  class rnb xxx
//CLASS FUNCTIONS   
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
#include <string>
using namespace std;
class node
{
    public:
	int value;
	int priorty;
	node* left;
	node* parent;
	node*right;
	string color;
	
	node(int value, int priorty, node* left, node* parent, node* right,string color)
	{
		this->left = left;
		this->right = right;
		this->value = value;
		this->priorty = priorty;
		this->parent = parent;
		this->color = color;
	}
	
	node()
	{
		left = NULL;
		right = NULL;
		value = 0;
		priorty = 0;
		parent = NULL;
		color = "GREY";
	}
};

class rnb
{
    public:
	node* root = NULL;
	
	int search_main(int key, node* NNode)
	{
	    if(NNode == NULL)
	    {
	       	cout << "NOT FOUND" << endl;
			return -1; 
	    }
		else if(NNode->priorty == key)
		{
			return NNode->priorty;
		}
		
		if(key > NNode->priorty)
		return search_main(key,NNode->right);
		else
		return search_main(key,NNode->left);
	}
	
	int search(int key)
	{
		return search_main(key,root);
	}
	
	/*  LEFT ROTATION => Anticlockwise rotation
				x						y
			a		y				x		c	
				     b     c			      a   b 
				
	*/
	
	void left_rotation(node* pNNode)
	{
		if(pNNode->right == NULL)
		return;
		else
		{
			node* y = pNNode->right;
			if(pNNode->parent != NULL)
			{
				if(pNNode->parent->left == NULL)
				{
					pNNode->parent->right = y;
					y->parent = pNNode->parent;
				}
				else if(pNNode->parent->left ==  pNNode)
				{
					pNNode->parent->left = y;
					y->parent = pNNode->parent;
				}
				else
				{	
					pNNode->parent->right = y;
					y->parent = pNNode->parent;
				}
			}
			else
			{
				y->parent = NULL;
				root = y;
			}
			
			if(y->left != NULL)
			pNNode->right = y->left;
			else
			pNNode->right = NULL;
			
			y->left = pNNode;
			pNNode->parent = y;
			return;
		}
	}
		
	void right_rotation(node* pNNode)
	{
		if(pNNode->left == NULL)
		return;
		else
		{
			node* x = pNNode->left;
			if(pNNode->parent != NULL)
			{
				if(pNNode->parent->right == NULL)
				{
					pNNode->parent->left = x;
					x->parent = pNNode->parent;
				}
				else if(pNNode->parent->right ==  pNNode)
				{
					pNNode->parent->right = x;
					x->parent = pNNode->parent;
				}
				else
				{	
					pNNode->parent->left = x;
					x->parent = pNNode->parent;
				}
			}
			else
			{
				x->parent = NULL;
				root = x;
			}
			
			if(x->right != NULL)
			pNNode->left = x->right;
			else
			pNNode->left = NULL;
			
			x->right = pNNode;
			pNNode->parent = x;
			return;
		}
	}
	
	// always added as leaf node
	// *** editing NNode after it is NULL does not change its value up the chain therefore parent needed;
	// THerefore be carefull;
	node* insert_main(int value, int priorty,node* NNode,node* parent = NULL)
	{
		node* returnNode;
		
		if(NNode == NULL || (NNode->priorty == -1 && NNode->value == -1 && NNode->color == "BLACK"))
		{
			node* newNode;
			node* nil1 = new node(-1,-1,NULL,newNode,NULL,"BLACK");
			node* nil2 = new node(-1,-1,NULL,newNode,NULL,"BLACK");
			newNode = new node(value,priorty,nil1,parent,nil2,"RED");
			if(priorty < parent->priorty)
			{
				parent->left = newNode;
			}
			else
			{
				parent->right = newNode;
			}
			return newNode;
		}
		if(priorty > NNode->priorty)
		returnNode = insert_main(value,priorty,NNode->right,NNode);
		else
		returnNode = insert_main(value,priorty,NNode->left,NNode);
		return returnNode;
	}
	
	void rnb_fixup(node* zNode)	//zNode will always be RED
	{
		// case 1: zNode and zNode-> parent both RED and yUncle_z = RED
			//edit color: color both yUncle_z and zNode->parent as BLAC and grandfather as red
			// Move z to new node  =>  new_z = zNode->parent->parent
		
		// case 2&3: zNode and zNode-> parent both RED and yUncle_z = BLACK
		// case 2: z is right child
			//left rotation		z and z->parent rotation //error is not fixed up instead transistion to case 3
			// Move z to new node => new_z = zNode->parent	(zNode before rotation or  left child of new zNode)
		// case 3: z is left child
			//right rotation 	z->parent and z->parent->parent **
			//edit color: old 	z->parent RED->BLACK and z->parent->parent BLACK ->RED
			//		new	z->parent RED->BLACK and z->parent->right  BLACK ->RED   **************does not work ??
		
		
		// case x_special: zNode does not have uncle;
		//		1Black				2RED			
		//	2RED 				3RED		1BLACK 
		//    3RED
		// and then color adjustment
		
		while( zNode->parent->color == "RED")
		{
			node* yUncle = (zNode->parent->parent->left == zNode->parent) ? zNode->parent->parent->right : zNode->parent->parent->left;	
			//cout << zNode->priorty << " " << zNode->color << endl;
			//cout << yUncle->priorty << " " << yUncle->color << endl;
			if(yUncle = zNode->parent->parent->left)
			{
				if (yUncle->color == "RED")
				 {
					// case 3.1
					yUncle->color = "BLACK";
					zNode->parent->color = "BLACK";
					zNode->parent->parent->color = "RED";
					zNode = zNode->parent->parent;
				} 
				else 
				{
					if (zNode == zNode->parent->left)
					 {
						// case 3.2.2
						zNode = zNode->parent;
						right_rotation(zNode);
					}
					// case 3.2.1
					zNode->parent->color = "BLACK";
					zNode->parent->parent->color = "RED";
					left_rotation(zNode->parent->parent);
				}
			}
			else
			{
				if(yUncle->color == "RED")
				{
					yUncle->color = "BLACK";
					zNode->parent->color = "BLACK";
					zNode->parent->parent->color = "RED";
					zNode = zNode->parent->parent;
				}
				else
				{

					if(zNode->parent->right == zNode)
					{
						zNode = zNode->parent;
						left_rotation(zNode);
					}
					zNode->parent->color = "BLACK";
					zNode->parent->parent->color = "RED";
					right_rotation(zNode->parent->parent);
					
				} 
			}
			if(zNode == root)
			break;
		}
		
		root->color = "BLACK";
		return;			
	}
		
	node* insert(int value,int priorty)
	{
	    if(root == NULL)
	    {
	    node* newNode;
	    node* nil1 = new node(-1,-1,NULL,newNode,NULL,"BLACK");
	    node* nil2 = new node(-1,-1,NULL,newNode,NULL,"BLACK");
	    newNode = new node(value,priorty,nil1,NULL,nil2,"BLACK");
		root = newNode;
		return root;
	    }
	    	node* newNode = insert_main(value,priorty,root);
	    	
	    	rnb_fixup(newNode);
		return newNode;
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
		if(NNode->right == NULL || (NNode->right->priorty == -1 && NNode->right->color == "BLACK" && NNode->right->value == -1) )
		return NNode;
		
		return maximum(NNode->right);
	}
	
	int maximum_bst()
	{
	    return maximum(root)->priorty;
	}
	
	node* minimum(node* NNode )
	{
		if(NNode->left == NULL || (NNode->left->priorty == -1 && NNode->left->color == "BLACK" && NNode->left->value == -1))
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
	
	int height_tree()
	{
		return height(root);
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
		if(NNode == NULL || (NNode->priorty == -1 && NNode->color == "BLACK" && NNode->value == -1))
		return height_n = 0;
		height_n = max(height(NNode->left) + 1,height(NNode->right) + 1);
		return height_n;
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
		if(NNode == NULL|| (NNode->priorty == -1 && NNode->color == "BLACK" && NNode->value == -1))
	    	return;
	    graphical_rep(NNode->left,max_height);
	    int depth_n = depth(NNode);
	    while(max_height != depth_n)
	    {
    		cout << "	";
    		depth_n++;
    	    } 
	    cout <<"(" <<NNode->value << ")" << NNode->priorty << ":" << NNode->color[0] << endl;
	    graphical_rep(NNode->right,max_height);
	}
	void print_graph()
	{
		graphical_rep(root,height_tree());
		return;
	}
	
		
};



#include <iomanip>
int main() {
    rnb tree;
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
    //cout << "Deleting Node:" << delete_this_node << endl;
    //tree.delete_node(delete_this_node);
    cout << endl;
    tree.print_graph();
    return 0;
}

