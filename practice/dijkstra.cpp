#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
    Dijkstra's Algorithm
    --------------------
    Finds the shortest distance from a start node
    to all other nodes in a weighted graph.

    Graph is represented using an adjacency list.
    Each entry: adj[u] = list of {v, weight}
*/

vector<int> run_dijkstra(vector<vector<pair<int, int>>> &adj, int start = 0)
{
    int n = adj.size();              // number of vertices

    // Distance array: initially all distances are "infinity"
    vector<int> dist(n, 1e9);

    /*
        Min Priority Queue
        ------------------
        Stores pairs of {distance, node}
        The node with the smallest distance is processed first
    */
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    // Distance from start node to itself is 0
    dist[start] = 0;

    // Push start node into priority queue
    pq.push({0, start});   // {distance, node}

    // Run until all reachable nodes are processed
    while (!pq.empty())
    {
        // Get node with minimum distance
        auto current = pq.top();
        pq.pop();

        int currentDist = current.first;   // distance till now
        int u = current.second;            // current node

        // Ignore outdated entries
        if (currentDist > dist[u])
            continue;

        // Traverse all neighbors of u
        for (auto edge : adj[u])
        {
            int v = edge.first;     // neighbor node
            int weight = edge.second; // edge weight

            // Calculate new distance
            int newDist = dist[u] + weight;

            // Relaxation step
            if (newDist < dist[v])
            {
                dist[v] = newDist;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances
    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; i++)
        cout << "Node " << i << " -> " << dist[i] << endl;

    return dist;
}

int main()
{
    /*
        Graph with 6 nodes (0 to 5)
        Each edge has a weight
    */

    vector<vector<pair<int, int>>> adj(6);

    // Undirected graph (add both directions)

    adj[0].push_back({1, 4});
    adj[1].push_back({0, 4});

    adj[0].push_back({2, 4});
    adj[2].push_back({0, 4});

    adj[1].push_back({2, 2});
    adj[2].push_back({1, 2});

    adj[1].push_back({3, 5});
    adj[3].push_back({1, 5});

    adj[2].push_back({3, 5});
    adj[3].push_back({2, 5});

    adj[2].push_back({4, 11});
    adj[4].push_back({2, 11});

    adj[3].push_back({4, 2});
    adj[4].push_back({3, 2});

    adj[3].push_back({5, 6});
    adj[5].push_back({3, 6});

    adj[4].push_back({5, 3});
    adj[5].push_back({4, 3});

    // Run Dijkstra from node 0
    run_dijkstra(adj, 0);

    return 0;
}
