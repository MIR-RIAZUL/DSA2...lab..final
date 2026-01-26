#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
    vector<vector<int>> adj(n);

    // build adjacency list
    for(auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]); // undirected
    }

    // distance array: min distance from source
    vector<int> dist(n, 1e9);
    dist[source] = 0;

    // priority queue: {distance_so_far, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, source});

    while(!pq.empty()) {
        auto node = pq.top();
        pq.pop();

        int d = node.first;
        int u = node.second;

        if(u == destination) return true; // reached destination

        if(d > dist[u]) continue; // already found better

        for(int v : adj[u]) {
            int new_dist = d + 1; // all edges have weight 1
            if(new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    return false; // destination not reachable
}

int main() {
    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    int source = 0;
    int destination = 2;

    if(validPath(n, edges, source, destination))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
