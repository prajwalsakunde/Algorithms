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
    int V;

    void addEdges(int src, int dest, int wt);
    int find(int parent[], int i);
    void Union(int parent[], int x, int y);
    void Kruskal();
};

void Graph::addEdges(int src, int dest, int wt)
{
    Edge edge;
    edge.src = src;
    edge.dest = dest;
    edge.wt = wt;
    edges.push_back(edge);
}

int Graph::find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Graph::Union(int parent[], int x, int y)
{
    int x_set = find(parent, x);
    int y_set = find(parent, y);

    parent[x_set] = y_set;
}

void Graph::Kruskal()
{
    vector<Edge> result;
    int parent[V];
    fill(parent, parent + V, -1);

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.wt < b.wt; });

    for (auto edge : edges)
    {
        int x = find(parent, edge.src);
        int y = find(parent, edge.dest);

        if (x != y)
        {
            result.push_back(edge);
            Union(parent, x, y);
        }
    }

    cout << "\nMST" << endl;
    for (auto edge : result)
    {
        cout << edge.src << " - " << edge.dest << " : " << edge.wt << endl;
    }
}

int main()
{
    ifstream fin; 
    fin.open("Kruskal.txt");
    if (!fin)
    {
        cerr << "Unable to open file";
        return 1;
    }

    Graph g;
    int edges, src, dest, wt;
    fin >> g.V;
    fin >> edges;

    for (int i = 0; i < edges; i++)
    {
        fin >> src >> dest >> wt;
        g.addEdges(src, dest, wt);
    }

    g.Kruskal();

    fin.close();
}