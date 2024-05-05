#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    map<int, list<int>> adj;
    map<int, bool> visited;
    queue<int> q;
    void addEdge(int src, int dest);
    void dfs(int node);
    void bfs(int start);
};  

void graph::addEdge(int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
    visited[src] = false; // Mark both nodes as unvisited initially
    visited[dest] = false;
}


void graph::dfs(int node)
{
    visited[node] = true;
    cout << node << "->";
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
}

void graph::bfs(int start)
{
    // Initialize with the starting node
    q.push(start);
    visited[start] = true; // Mark the starting node as visited

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << "->";
        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}


int main()
{
    fstream fin;
    fin.open("input.txt");
    if (!fin)
    {
        cerr << "Unable to open file!!";
        return 1;
    }

    graph g;
    int edges, src, dest;
    fin >> edges;
    for (int j = 0; j < edges; j++)
    {
        fin >> src >> dest;
        g.addEdge(src, dest);
    }

    int start;
    cout<<"Enter the starting point: ";
    cin>>start;
    cout << "DFS on the given graph is ";
    g.dfs(start);
    cout << endl;

     for (auto &entry : g.visited)
    {
        entry.second = false;
    }

     cout << "BFS on the given graph is : ";
    g.bfs(start);
    cout << endl;

    fin.close();
}