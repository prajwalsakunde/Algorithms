#include <bits/stdc++.h>
using namespace std;

struct City
{
    string name;
    unordered_map<string, int> neighbors;
};

// Define the map of Romania as a graph with a subset of cities
unordered_map<string, City> romania_map = {

    {"Arad", {"Arad", {{"Sibiu", 140}, {"Timisoara", 118}}}},
    {"Sibiu", {"Sibiu", {{"Arad", 140}, {"Fagaras", 99}}}},
    {"Timisoara", {"Timisoara", {{"Arad", 118}, {"Lugoj", 111}}}},
    {"Fagaras", {"Fagaras", {{"Sibiu", 99}, {"Bucharest", 211}}}},
    {"Bucharest", {"Bucharest", {{"Fagaras", 211}}}}};

// Heuristic values for each city
unordered_map<string, int> heuristic_values = {
        {"Arad", 366},
        {"Sibiu", 253},
        {"Timisoara", 329},
        {"Fagaras", 176},
        {"Bucharest", 0}};

vector<string> astar(const string &start, const string &goal)
{
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    unordered_map<string, int> CostSoFar;
    unordered_map<string, string> CameFrom;

    pq.push({0, start});
    CostSoFar[start] = 0;

    while (!pq.empty())
    {
        string currct = pq.top().second;
        pq.pop();

        if (currct == goal)
        {
            break;
        }

        for (const auto &neigh : romania_map[currct].neighbors)
        {
            string next_city = neigh.first;
            int new_cost = heuristic_values[next_city] + neigh.second + CostSoFar[currct];

            if (!CostSoFar.count(next_city) || new_cost < CostSoFar[next_city])
            {
                CostSoFar[next_city] = new_cost;
                int prior = heuristic_values[next_city] + new_cost;
                pq.push({prior, next_city});
                CameFrom[next_city] = currct;
            }
        }
    }

    vector<string> path;
    string curr = goal;
    while (curr != start)
    {
        path.push_back(curr);
        curr = CameFrom[curr];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    string start = "Arad";
    string goal = "Fagaras";

    vector<string> path = astar(start, goal);

    if (!path.empty())
    {
        cout << "Path from " << start << " to " << goal << ":" << endl;
        for (const auto &city : path)
        {
            cout << city << "--";
        }
        cout << endl;
    }
    else
    {
        cout << "No path found!" << endl;
    }
    return 0;
}