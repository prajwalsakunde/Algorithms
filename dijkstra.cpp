#include<iostream>
#include<fstream>
#include<map>
#include<list>
#include<queue>
#include<limits.h> // for INT_MAX
using namespace std;

class Graph {
public:
    map<int, list<pair<int,int>>> adj; // Adjacency list with weights
    map<int, int> distance; // Distance of each vertex from source
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // Min heap for Dijkstra's algorithm

    void addEdge(int src, int dest, int wt);
    void dijkstra(int src);
};

void Graph::addEdge(int src, int dest, int wt) {
    adj[src].push_back(make_pair(dest, wt));
    adj[dest].push_back(make_pair(src, wt));
}

void Graph::dijkstra(int src) {
    for(auto i: adj) {
        distance[i.first] = INT_MAX; // Set initial distances to infinity to each vertex 
    }
    distance[src] = 0; // Distance from source to itself is 0
    pq.push(make_pair(0, src)); // Push source vertex with distance 0 into priority queue

    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();
        for (auto i : adj[node]) {
            int v = i.first;
            int weight = i.second;
            if (distance[v] > distance[node] + weight) {
                distance[v] = distance[node] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }
}

int main() {
    ifstream inFile;
    inFile.open("Dijkstra.txt"); // Open input file
    if (!inFile) {
        cerr << "Unable to open file graph.txt";
        return 1;
    }

    Graph g;
    int edges, src, dest, wt;
    inFile >> edges; // Read number of edges

    for (int i = 0; i < edges; ++i) {
        inFile >> src >> dest >> wt; // Read edge data
        g.addEdge(src, dest, wt); // Add edge to the graph
    }

    g.dijkstra(0); // Perform Dijkstra's algorithm with source vertex 0

    cout << "Shortest distances from source vertex 0:\n";
    for (auto d : g.distance) {
        cout << "Vertex " << d.first << ": " << d.second << endl; // Print shortest distances
    }

    inFile.close(); // Close input file

    return 0;
}