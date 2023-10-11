// adjacency Matrix ----------> Shortest distance matrix (same matrix overwrite)
// Here INF is used to denote edge does not exist between two vertices.(instead of our standard 0)
//	DP based algorithm
// Time Complexity: O(N^3)
// Space Complexity: O(1)

/* This algorithm checks for i,j vertices if distance between them would decrease if we go via a third vertex k
	So for each i,j we will check for each vertex in graph that going through them, (if possible: meaning edge exist  i->k->j)
	that distance has decrease or not.
	
	One other approach will be to start with via loop like if every route was via 2 then choose every i,j which fit condition and edit the distance
*/
#define V 4
#define INF 2100000000

void floydWarshall(int graph[][V])
{
	for(int i = 0; i < V; i++)
		for(int j = 0; j< V; j++)
			for(int k = 0; k< V; k++)
				if(graph[i][j] > (graph[i][k] + graph[k][j]) && (graph[k][j] != INF && graph[i][k] != INF))
					graph[i][j] = graph[i][k] + graph[k][j];
}

void floydWarshall_via(int graph[][V])
{
	for(int k = 0; k < V; k++)
		for(int i = 0; i < V; i++)
			for(int j = 0; j < V; j++)
				if(graph[i][j] > (graph[i][k] + graph[k][j]) && ((graph[k][j] != INF && graph[i][k] != INF) && i!= k && j != k))
					graph[i][j] = graph[i][k] + graph[k][j];
}


				
