//class to create adjacency list from scratch/adjacency matrix
// adjacency matrix--------constructor(adjacencylist() ) --------> adjacency list
// addEdge(to vertex, from vertex, weight) -----------------> adjacency list

#include <iostream>
#include <vector>
using namespace std;

class node
{
    public:
	int val;
	int weight;
	node* next;
	
	node(int value,int w)
	{
	   
		val = value;
		weight = w;
		next = NULL;
    	}
};
class list
{
	public:
	node* head = NULL;
	
	void push_back(int valx,int weight)
	{
		if(head == NULL)
		{
			node* newNode = new node(valx, weight);
			head = newNode;
		}
		else
		{
			node* trav = head;
			while(trav->next != NULL)
			{
				trav = trav->next;	
			}
			node* newNode = new node(valx, weight);
			trav->next = newNode;
		}
	}
	void print()
	{
	   node* trav = head;
	   while(trav != NULL )
	   {
	        cout << trav->val << "(" << trav->weight << ")";
	        if(trav->next != NULL)
	        cout << "->";
	        trav = trav->next;
	   }
	}
};
class adjacency_list 
{
	public:
	 vector<list*> adjList;
	 
	 adjacency_list(int n = 10)				//initialising vector adjList
	 {
	       for(int i = 0; i< n; i++)
	       adjList.push_back(NULL);				//default values
	 }
	 adjacency_list(vector<vector<int>> matrix)
	 {
	    for(int i = 0; i< matrix.size(); i++)
	    adjList.push_back(NULL);
	    
	 	for(int i = 0; i< matrix.size(); i++)
	 	for(int j = 0; j< matrix[i].size(); j++)
	 	{
	 	    
	 		if( matrix[i][j] != 0)
	 		{
	 		addEdge(i,j,matrix[i][j]);
	 		}
	 	}
	 }
	 void addEdge(int vertex1,int vertex2, int weight = 1)
	{
	    if(adjList[vertex1] == NULL)
	    {
	            list* ll = new list();
	            ll->push_back(vertex2, weight);
	            adjList[vertex1] = ll;
	            
	    }
	    else
	    {
            list* ll = adjList[vertex1];
            ll->push_back(vertex2,weight);
	    }
	}
	void print()
	{
		for (int i = 0; i< adjList.size(); i++)
		{
            list* listt = adjList[i];
            cout << i << ":";
            if( listt == NULL)			//because if edge not added then list not created therefore not printed
            {
                cout << "NULL" << endl;
                continue;
            }
            listt->print();
            cout << endl;
            
		}
	}
			
	
};
