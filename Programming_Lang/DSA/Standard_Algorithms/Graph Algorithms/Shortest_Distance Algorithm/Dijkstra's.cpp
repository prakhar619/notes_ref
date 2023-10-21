// adjacency matrix(2d array with edge 0 as 0), source_vertex(int) -----------> <print>shortest distance(array form)
// uses 2 * #define INT_MAX,V
// Greedy and DP

// Time Complexity: O(V^2)
// Space Complexity: O(V)
/*
		2 array: sptset    --stores which target vertex shortest path already finalised
			distance   --stores the shortest path distance
			
		1 subroutine: minDistance   --gives the vertex which is at shortest distance from all vertex which is not present is sptset(already finalised)
						-- input is shortest path distance arry , finalised vertex sptset
				
		Here how we do it:
		We first find distance of vertex from src vertex. Then we update those distances in distance vertex(from src to adjacent vertex)
		Then we find the shortest vertex among those vertex by using the minDistace().
		Then we update sptset as we now the shortest distance to that vertex.
		Then we again find the distance of vertex pt from this vertex.
		
		Its not necessary that new point always give pt to sptset.
		minDistance just give vertex which is at shortest distance to a notspt vertex. Does not matter what point from.
		We will repeat this process V-1 times because we already know the distance to src vertex
		
		Whole process is kind of Discovering->FindingMin->Finalising->Discover->...
		This discovering can be from Max to a new edge or Finding a new smaller edge.
*/
#include <iostream>
using namespace std;

#define INT_MAX 2100000000
#define V 9
int minDistance(int distance[], int sptset[])
{
	int min = INT_MAX;
	int min_index;
	
	for(int v = 0; v< V; v++)
	{
		if(sptset[v] != 1 && distance[v] <= min)
		{
			min = distance[v];
			min_index = v;
		}
	}
	return min_index;
}


void dijkstra_primsAlgo(int graph[][V], int src)
{
	int distance[V];	//holds distance from src to every other vertex
	int sptset[V];		//sptset[i] == 1 when distace from src to i is finalised/relaxed
	
	for(int i = 0; i< V; i++)
	{
		distance[i] = INT_MAX;
		sptset[i] = 0;
	}
	
	distance[src] = 0;
	
	for(int i = 0; i < V-1; i++)
	{
		int u = minDistance(distance,sptset);	//u is src in at first
		
		sptset[u] = 1;		//u is finalised now(distance fixed)
		
		for(int v= 0; v<V; v++)		//updating adjacent vertices distance from finalized vertex
		{
			// only when adjacent vertex is not finalised yet and there exist edge b/w them
			// and d(u) + c(u,v) < d(v)
			// then d(v) = d(u)+c(u,v)
			if( sptset[v] != 1 && graph[u][v] && distance[u] + graph[u][v] < distance[v])
				distance[v] = distance[u]+graph[u][v];
		}
	}	
	for(int i = 0; i< V; i++)
	cout << distance[i] << endl;
}











class asc_priortyQ_heap
{
	public:
	int *priorty_ar;
	int *value_ar;
	int len;
	
	asc_priortyQ_heap()
	{
		priorty_ar = NULL;
		value_ar = NULL;
		len = 0;
	}
	
	asc_priortyQ_heap(int* value,int* prior,int len)
	{
		priorty_ar = prior;
		value_ar = value;
		this->len = len;
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
	
	
	void push(int val, int priorty)
	{
		int* newarray_p = new int(len+1);
		int* newarray_v = new int(len+1);
		for(int i  = 0; i< len; i++)
		{
			newarray_p[i] = priorty_ar[i];
			newarray_v[i] = value_ar[i];
		}
		newarray_p[len] = priorty;
		newarray_v[len] = val;
		
		priorty_ar = newarray_p;
        value_ar = newarray_v;
		len++;
		
		build_min_heapify(value_ar,priorty_ar,len);
	}
	
		
	void pop(int pos_index = 0)
	{
		swap(priorty_ar[pos_index],priorty_ar[len-1]);
		swap(value_ar[pos_index],value_ar[len-1]);
		len--;
		min_heapify(value_ar,priorty_ar,len,pos_index);
	}
	
	int empty()
	{
		if(len == 0)
		return 1;
		return 0;
	}
	
	int top()
	{
		return value_ar[0];
	}
	
	
	void print()
	{
	    for(int i = 0; i< len; i++)
	    {
	        cout << "(" << value_ar[i] << " "<< priorty_ar[i] << ")" << ":" ;
	    }
	    cout << endl;
	}

};

// adjacency_matrix(2d array), source vertex(int) ---------> <print> shortest distance(array form)
// uses #define INT_MAX and V and priortyQueue(min heap)
// Time Complexity: O(E logV)	where E edge and V vertex
// Space Complexity: O(V)

/* Here we are doing the same 
	Discovering ->Finding Min ->Finalising ->Discovering
	
	But we are not here Finding Min using function. Instead we are using priorty heap which will 
	find the vertex at min when pushing.
	
	Also we are sometimes push vertex with notMin distance but once min found not pushing on queue.
	
*/

void dijkstra_pQueue(int graph[][V], int src)
{
	int distance[V];
	for(int i = 0; i< V; i++)
	{
		distance[i] = INT_MAX;
	}
	
	asc_priortyQ_heap prioQueue;
	prioQueue.push(src,0);
	distance[src] = 0;

	while(!prioQueue.empty())
	{
		int u = prioQueue.top();
		prioQueue.pop();
		
		for(int i = 0; i<V;i++)
		{
			if( distance[i] > distance[u] + graph[u][i] && graph[u][i])
			{
				distance[i] = distance[u]+graph[u][i];
				prioQueue.push(i,distance[i]);
			}
		}
	}	
	for(int i = 0; i< V; i++)
	cout << distance[i] << endl;
}
		
		
	
	




