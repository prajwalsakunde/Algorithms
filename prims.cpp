#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src, dest, wt;
};

class Graph
{
public:
    vector<Edge> edges;
    vector<vector<pair<int, int>>> adj;
    int V;

    void addEdge(int src, int dest, int wt);
    int primMST();
};

void Graph::addEdge(int src, int dest, int wt)
{
    Edge edge;
    edge.src = src;
    edge.dest = dest;
    edge.wt = wt;
    edges.push_back(edge);
}

int Graph::primMST()    
{
    vector<int> key(V + 1, INT_MAX);
    vector<bool> mst(V + 1, false);
    vector<int> parent(V + 1, -1);

    for (int i = 0; i <= V; i++)
    {
        adj.push_back(vector<pair<int, int>>());
    }

    for (Edge edge : edges)
    {
        adj[edge.src].push_back({edge.dest, edge.wt});
        adj[edge.dest].push_back({edge.src, edge.wt});
    }

    key[1] = 0;

    for (int i = 1; i < V; i++)
    {
        int mini = INT_MAX;
        int u;

        for (int v = 1; v <= V; v++)
        {
            if (!mst[v] && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        mst[u] = true;

        for (auto i : adj[u])
        {
            int v = i.first;
            int w = i.second;
            if (!mst[v] && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    cout << "\nMST " << endl;
    int costMST=0;
    cout << "src_vertex" << "---weight---> " << "dest_vertex" << endl;
    for (int i = 2; i <= V; i++)
    {
        cout << parent[i] << "\t----"<< key[i]<<"---> \t" << i << endl;
        costMST +=key[i];
    }
    return costMST;
}

int main()
{
    ifstream fin; 
    fin.open("Prims.txt");
    if (!fin)
    {
        cerr << "Unable to open file!!";
        return 1;
    }
    Graph g;
    int edges, src, dest, wt;
    fin >> g.V;
    fin >> edges;

    for (int i = 0; i < edges; i++)
    {
        fin >> src >> dest >> wt;
        g.addEdge(src, dest, wt);
    }
    int costMST;

    costMST= g.primMST();
    cout<<"COST OF MST: " <<costMST<<endl;

    fin.close();
}