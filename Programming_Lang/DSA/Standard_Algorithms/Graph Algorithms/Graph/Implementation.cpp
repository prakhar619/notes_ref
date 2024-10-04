#include "Graphs.cpp"

class AdjacencyMatrix : public Graph
{
    private:
    fstream fobj;
    int minDistance(vector<int>&dist, vector<bool>&sptSet)
    {
        int min = INT_MAX;
        int min_index;
        for(int v = 0; v < dist.size(); v++)
        {
            if(sptSet[v] == false && dist[v] <= min)
            {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    public:
        vector<vector<int>> Matrix;

        AdjacencyMatrix(string filename)
        {
            fobj.open(filename, ios::in);
            int vertex;
            fobj >> vertex;
            Matrix.resize(vertex, vector<int>(vertex,0));
            for(int i = 0; i < vertex; i++)
            for(int j = 0; j < vertex; j++)
            {
                fobj >> Matrix[i][j];
            }
        }
        AdjacencyMatrix(vector<vector<int>> M)
        {
            Matrix = M;
        }

        vector<int> djikstras(int src)
        {
            vector<int> dist(Matrix.size(), INT_MAX);
            vector<bool> sptSet(Matrix.size(), false);  //Shortest Path Tree

            dist[src] = 0;
            
            for(int i = 0; i < Matrix.size() -1; i++)
            {
                int minDistanceVertex = minDistance(dist,sptSet);
                sptSet[minDistanceVertex] = true;

                for(int v = 0; v < dist.size(); v++)
                {
                    if(!sptSet[v] && Matrix[minDistanceVertex][v] != INT_MAX && dist[minDistanceVertex] != INT_MAX)
                    {
                        dist[v] = min(dist[minDistanceVertex] + Matrix[minDistanceVertex][v], dist[v]);
                    }
                }
            }
            return dist;
        }

        vector<int> bellmanFord(int src)
        {
            vector<int> dist(Matrix.size(), INT_MAX);
            dist[src] = 0;

            for(int i = 0; i < Matrix.size()-1; i++)
            {
                // j and k loop gives edge   //Matrix[j][k] is one edge
                for(int j = 0; j < Matrix.size(); j++)
                {
                    for(int k = 0; k < Matrix[j].size(); k++)
                    {
                        int w = Matrix[j][k];
                        if(dist[j] != INT_MAX && w != INT_MAX)
                        {
                            dist[k] = min(dist[j] + w, dist[k]);
                        }
                    } 
                }
            }
            //check for negative cycle
            for(int j = 0; j < Matrix.size(); j++)
            {
                for(int k = 0; k < Matrix.size(); k++)
                {
                    int w = Matrix[j][k];
                    if(dist[j] != INT_MAX && w != INT_MAX && dist[k] > dist[j] + w)
                    {
                        cout << "Graph Contains Negative Cycle" << endl;
                        return vector<int>(Matrix.size(), INT_MIN);
                    }

                }
            }
            return dist;
        }

        vector<int> floydWarshall(int src)
        {
            vector<vector<int>> graph = Matrix;
            for(int k = 0; k < graph.size(); k++)
            {
                for(int i = 0; i < graph.size(); i++)
                {
                    for(int j = 0; j < graph.size(); j++)
                    {
                        if(graph[i][k] != INT_MAX && graph[k][j] != INT_MAX && i != k && k != j)
                        {
                            graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
                        }
                    }
                }
            }
            return graph[src];
        }

        Graph* kruskal()
        {
            vector<vector<int>> edgeList;
            for(int i = 0; i < Matrix.size(); i++)
            {
                for(int j = 0; j < Matrix[i].size(); j++)
                {
                    edgeList.push_back({Matrix[i][j],i,j});
                }
            }
            sort(edgeList.begin(), edgeList.end());
            vector<vector<int>> newMatrix(Matrix.size(), vector<int>(Matrix.size(),INT_MAX));

            DSU minSpanEdge(Matrix.size());
            for(vector<int> edge: edgeList)
            {
                int w = edge[0];
                int x = edge[1];
                int y = edge[2];
                if(x == y)
                {
                    newMatrix[x][y] = 0;
                    continue;
                }
                if(minSpanEdge.Find(x) != minSpanEdge.Find(y))
                {
                    minSpanEdge.Union(x,y);
                    newMatrix[x][y] = w;
                }
            }

            for(int i = 0; i < newMatrix.size(); i++)
            {
                for(int j = 0; j < newMatrix.size(); j++)
                {
                    newMatrix[i][j] = min(newMatrix[i][j], newMatrix[j][i]);
                    newMatrix[j][i] = min(newMatrix[i][j], newMatrix[j][i]);
                }
            }


            Graph* G = new AdjacencyMatrix(newMatrix);
            return G;
        }

        Graph* prim()
        {
            vector<bool> mstSet (Matrix.size(),false);
            vector<int> parent (Matrix.size());
            vector<int> dist(Matrix.size(), INT_MAX);       //not actual distance // edge weights only

            for(int i = 0; i < parent.size(); i++)
            {
                parent[i] = i;
            }

            int startV = 0;
            dist[startV] = 0;

            for(int i = 0; i < Matrix.size()-1; i++)
            {
                int minV = minDistance(dist,mstSet);
                mstSet[minV] = true;

                for(int v = 0; v < dist.size(); v++)
                {
                    if(!mstSet[v] && Matrix[minV][v] != INT_MAX && dist[minV] != INT_MAX)
                    {
                        if(dist[v] > Matrix[minV][v] )
                        {
                            dist[v] = Matrix[minV][v];      //Not actual distance
                            parent[v] = minV;
                        }
                    }
                }
            }

            vector<vector<int>> newMatrix (Matrix.size(), vector<int>(Matrix.size(),INT_MAX));
            for(int i = 0; i < parent.size(); i++)
            {

                newMatrix[parent[i]][i] = min(Matrix[parent[i]][i], Matrix[i][parent[i]]);
                newMatrix[i][parent[i]] = min(Matrix[parent[i]][i], Matrix[i][parent[i]]);
                newMatrix[i][i] = 0;
            }

            Graph* ptr = new AdjacencyMatrix(newMatrix);
            return ptr;
        }

        void print()
        {
            for(vector<int> v: Matrix)
            {
                for(int i : v)
                cout << i << " ";
                cout << endl;
            }
        }
};

class AdjacencyList : public Graph
{    
    private:
        fstream fobj;
        int minDistance(vector<int>&dist, vector<bool>&sptSet)
        {
            int min = INT_MAX;
            int min_index;
            for(int v = 0; v < dist.size(); v++)
            {
                if(sptSet[v] == false && dist[v] <= min)
                {
                    min = dist[v];
                    min_index = v;
                }
            }
            return min_index;
        }

    public:
        int vertex;
        unordered_map<int,vector<pair<int,int>>> list;

        AdjacencyList(string filename)
        {
            fobj.open(filename, ios::in);
            fobj >> vertex;
            for(int i = 0; i < vertex; i++)
            for(int j = 0; j < vertex; j++)
            {
                int weight;
                fobj >> weight;
                if(weight != INT_MAX)
                {
                    list[i].push_back({j,weight});
                }
            }
        }

        AdjacencyList(int vertex, unordered_map<int,vector<pair<int,int>>> list)
        {
            this->vertex =vertex;
            this->list = list;
        }

        vector<int> djikstras(int src)
        {
            vector<int> dist(vertex, INT_MAX);
            vector<bool> sptSet(vertex, false);  //Shortest Path Tree

            dist[src] = 0;
            
            for(int i = 0; i < vertex -1 ; i++)
            {
                int minDistanceVertex = minDistance(dist,sptSet);
                sptSet[minDistanceVertex] = true;

                for(int j = 0; j < list[minDistanceVertex].size(); j++)
                {
                    int v = list[minDistanceVertex][j].first;
                    int w = list[minDistanceVertex][j].second;
                    if(!sptSet[v] && dist[minDistanceVertex] != INT_MAX)
                    {
                        dist[v] = min(dist[minDistanceVertex] + w, dist[v]);
                    }
                }
            }
            return dist;
        }

        vector<int> bellmanFord(int src)
        {
            vector<int> dist(vertex, INT_MAX);
            dist[src] = 0;

            for(int i = 0; i < vertex -1; i++)
            {
                // j and k loop gives edge   //Matrix[j][k] is one edge
                for(pair<int,vector<pair<int,int>>> li : list)
                {
                    int j = li.first;
                    for(pair<int,int> edge: li.second)
                    {
                        int k = edge.first;
                        int w = edge.second;
                        if(dist[j] != INT_MAX)
                        {
                            dist[k] = min(dist[j] + w,dist[k]);
                        }
                    }
                }
            }

            //check for negative cycle
            for(pair<int,vector<pair<int,int>>> li : list)
            {
                int j = li.first;
                for(pair<int,int> edge: li.second)
                {
                    int k = edge.first;
                    int w = edge.second;
                    if(dist[j] != INT_MAX && dist[k] > dist[j] + w)
                    {
                        cout << "Graph Contains Negative Cycle" << endl;
                        return vector<int>(vertex, INT_MIN);
                    }
                }
            }
            return dist;
        }

        vector<int> floydWarshall(int src)
        {
            unordered_map<int,vector<pair<int,int>>> graph = list;
            return vector<int>(vertex,INT_MAX);
        }

        Graph* kruskal()
        {
            vector<vector<int>> edgeList;
            for(pair<int, vector<pair<int,int>>> p : list)
            {
                int i = p.first;
                for(pair<int,int> edge: p.second)
                {
                    int j = edge.first;
                    int w = edge.second;
                    edgeList.push_back({w,i,j});
                }
            }
            sort(edgeList.begin(), edgeList.end());
            unordered_map<int, vector<pair<int,int>>> newList;

            DSU minSpanEdge(vertex);
            for(vector<int> edge: edgeList)
            {
                int w = edge[0];
                int x = edge[1];
                int y = edge[2];
                if(x == y)
                {
                    continue;
                }
                if(minSpanEdge.Find(x) != minSpanEdge.Find(y))
                {
                    minSpanEdge.Union(x,y);
                    newList[x].push_back({y,w});
                }
            }

            Graph* G = new AdjacencyList(vertex,newList);
            return G;
        }

        Graph* prim()
        {
            vector<bool> mstSet (vertex,false);
            vector<int> parent (vertex);
            vector<int> dist(vertex, INT_MAX);       //not actual distance // edge weights only

            for(int i = 0; i < parent.size(); i++)
            {
                parent[i] = i;
            }

            int startV = 0;
            dist[startV] = 0;

            for(int i = 0; i < vertex-1; i++)
            {
                int minV = minDistance(dist,mstSet);
                mstSet[minV] = true;

                for(int j = 0; j < list[minV].size(); j++)
                {
                    int v = list[minV][j].first;
                    int w = list[minV][j].second;
                    if(!mstSet[v] && dist[minV] != INT_MAX)
                    {
                        if(dist[v] > w  )
                        {
                            dist[v] = w;      //Not actual distance
                            parent[v] = minV;
                        }
                    }
                }

            }

            unordered_map<int,vector<pair<int,int>>> newList;
            for(int i = 0; i < parent.size(); i++)
            {
                int w = -1;
                for(int j = 0; j < list[parent[i]].size(); j++)
                {
                    if(list[parent[i]][j].first == i)
                    {
                        w = list[parent[i]][j].second;
                    }
                }
                newList[parent[i]].push_back({i,w});
            }

            Graph* ptr = new AdjacencyList(vertex, newList);
            return ptr;       
        }

        void print()
        {
            for(pair<int,vector<pair<int,int>>> p: list)
            {
                cout << p.first << ":";
                for(pair<int,int> v : p.second)
                {
                    cout << "(" << v.first << "|" << v.second << ")";
                }
                cout << endl;
            }
        }

};

class NodeGraph
{
    //TODO Tree like Graph Structure
};

int main()
{
    string file = "./Matrix.txt";
}