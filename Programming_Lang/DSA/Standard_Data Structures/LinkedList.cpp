// INCOMPLETE  remove_node;erase

/* Linked List
*/

// Time Complexity:	
//CLASS FUNCTIONS
//			push_back(value):	O(1)
//			push_front(value): 	O(1)
//			pop_front(): 		O(1)
//			pop_back():		O(1)
//			int front():		O(1)
//			int back():		O(1)
//			insert(value,index):	O(N)
//			erase()			O(N)
//			remove(index)		O(N)

//CLASS WORKING FUNCTIONS
//			print():		O(N)
//			dev_print():		O(N)
#include <iostream>
using namespace std;
class node
{
    public:
    node* prev;
    int val;
    node* next;
    
    node(node* prev0,int value0,node* next0)
    {
        prev = prev0;
        val = value0;
        next = next0;
    }
    node()
    {
    	prev = NULL;
    	val = 0;
    	next = NULL;
    }
};

class LinkedList
{
    public:
    node* head = NULL;
    node* tail = NULL;
    int front()
    {
    	return head->val;	
    }
    int back()
    {
    	node *trav = head;
    	while(trav->next != NULL)
    		trav = trav->next;
    	return trav->val;
    }
    void push_back(int valx)
    {
    	if(head == NULL)	
    	{
    	    node* newNode = new node(NULL,valx,NULL);
    		head = newNode;
    		tail = newNode;
    	}
    	else
    	{
    		node* newNode = new node(tail,valx,NULL);
    		tail->next = newNode;
    		tail = newNode;
    	}
    }
    
    void push_front(int valx)
    {
    	if(head == NULL)	
    	{
    	    node* newNode = new node(NULL,valx,NULL);
    		head = newNode;
    		tail=  newNode;
    	}
    	else
    	{
    		node* newNode = new node(NULL,valx,head);
    		head->prev = newNode;
    		head = newNode;
    	}
    }

    void pop_front()
    {
            node* tempNode = head;
    		head = head->next;
    		head->prev= NULL;
    		free(tempNode);
    }
    void pop_back()
    {
        node* tempNode = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(tempNode);
    }
    int insert(int valx,int index)
    {
    	int counter = 0;
    	node* trav = head;
    	while(counter != index)
    	{
    		trav = trav->next;
    		counter++;
    	}
    		node* newNode = new node(trav->prev,valx,trav);
    		trav->prev->next = newNode;
    		trav->prev = newNode;
    }
    void remove_node(int index =  0)
    {
     	int counter = 0;
     	node* trav = head;
     	if(index = 0)
     	{
    		pop_front();
    		return;
    	}
    	cout << "hear" << endl;
     	while(counter != index)
     	{
     	    cout << trav->val << endl;l
     		trav=  trav->next;
     		
     		counter++;
     	}	
     	if(trav->next = NULL)
     	{
     		pop_back();
     		return;
     	}
     		trav->prev->next = trav->next;
     		trav->next->prev = trav->prev;
    }
    void erase()
    {
    	node* trav=  head;
    	while(trav != NULL)
    	{
    	 	node* tempNode = trav;
    	 	trav = trav->next;
    	 	free(tempNode);
    	 }
    }
    
    
    void print()
    {
    	node* trav = head;
    	while(trav != NULL)
    	{
    	    cout << trav->val;
    	    if(trav->next != NULL)
    	    cout << ":";
    	    trav = trav->next;
    	}
    	cout << endl;
    }
    
    void dev_print()
    {
        node* trav = head;
        if(trav == NULL)
        cout << "NULL"   << endl;
    	while(trav != NULL)
    	{
    	    cout << trav << "->" <<trav->prev << ":"<<trav->val <<":"<< trav->next;
    	    trav = trav->next;
    	    cout << endl;
    	}
    }
/*   int assign()
    {}
    
    int reverse()
    {}
    int sort()
    {}
    int list_merge()
    {}
*/
};

