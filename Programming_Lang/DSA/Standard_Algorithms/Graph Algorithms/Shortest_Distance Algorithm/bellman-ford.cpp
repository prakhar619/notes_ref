//incomplete
//Time complexity: O(VE)
//Space Complexity: :O(E)

/* Bellman ford works on principal same as dijkstra but instead of choosing vertex connected to standing vertex
we go through as Edges (n-1 times) as with each edge we get to vertex, from vertex, and weight.
THen we check distance[to] > distance[from] + weight;

/* To check negative weight cycle go through all edges once more; 
if you are able to relax a node (like distance[to] > distance[from] + weight) then graph contains negative cycle;
*/
