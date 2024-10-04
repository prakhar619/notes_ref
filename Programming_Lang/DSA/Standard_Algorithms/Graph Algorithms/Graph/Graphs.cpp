#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class DSU
{
    vector<int> parent;
    vector<int> rank;
    public:
        DSU(int n)
        {
            parent.resize(n);
            rank.resize(n);
            for(int i = 0; i < n; i++)
            {
                parent[i] = i;
                rank[i] = 1;
            }
        }
        int Find(int o)
        {
            if(parent[o] == o)
                return parent[o];
            
            parent[o] = Find(parent[o]);
            return parent[o];
        }
        void Union(int a, int b)
        {
            int pa = Find(a);
            int pb = Find(b);

            if( pa != pb)
            {
                if(rank[pa] < rank[pb])
                {
                    parent[pa] = pb;
                    rank[pb] += rank[pa];
                }
                else
                {
                    parent[pb] = pa;
                    rank[pa] += rank[pb];
                }
            }
        }
};

class Graph
{
    public:
    virtual void print() = 0;
    virtual vector<int> djikstras(int src) = 0;               
// Djikstras Algorithm
// Weighted Directed Graph 
// No Negative Cycle
// INT_MAX in Edge weight means No Edge
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
    
    virtual vector<int> bellmanFord(int src) = 0;   
// Bellman-Ford
// Weighted Directed Graph 
// Negative Cycle Allowed      
// INT_MAX in Edge weight means No Edge
// Time complexity: O(VE)
// Space Complexity: :O(E)
/* 
    Bellman ford works on principal same as dijkstra but instead of choosing vertex connected to standing vertex
    we go through as Edges (n-1 times) as with each edge we get to vertex, from vertex, and weight.
    THen we check distance[to] > distance[from] + weight;

    To check negative weight cycle go through all edges once more; 
    if you are able to relax a node (like distance[to] > distance[from] + weight) then graph contains negative cycle;
*/

    virtual vector<int> floydWarshall(int src) = 0;
// Floyd Warshall
// Here INT_MAX is used to denote edge does not exist between two vertices.(instead of our standard 0)
//	DP based algorithm
// Time Complexity: O(N^3)
// Space Complexity: O(1)

/* This algorithm checks for i,j vertices if distance between them would decrease if we go via a third vertex k
	So for each i,j we will check for each vertex in graph that going through them, (if possible: meaning edge exist  i->k->j)
	that distance has decrease or not.
	
	One other approach will be to start with via loop like if every route was via 2 then choose every i,j which fit condition and edit the distance
*/
    virtual Graph* kruskal() = 0;                   // TODO: unknown behaviour for asymmetric matrix
// Time Complexity: O(E * logV)
// Space Complexity: O(V+E)

    virtual Graph* prim() = 0;                      // TODO: unknown behaviour for asymmetric matrix
// Time Complexity: O(V^2) (Matrix)     O(E * logV) (List)
// Space Complexity: O(V)

    // virtual vector<int> bfs(int src) = 0;        
//Unweighted Directed Graph
    // virtual vector<int> johnson(int src) = 0;   
    // virtual vector<int> dfs(int src) = 0;
};
