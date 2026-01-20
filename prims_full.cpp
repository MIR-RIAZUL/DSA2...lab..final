#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Min-heap comparator based on weight
struct CompareNodes {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

void prims(vector<vector<pair<int,int>>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        CompareNodes
    > pq;

    pq.push({0, 0}); // {node, weight}
    int cost = 0;

    while (!pq.empty()) {
        auto node = pq.top();
        pq.pop();

        int u = node.first;
        int u_w = node.second;

        if (visited[u])
            continue;

        visited[u] = true;
        cost += u_w;

        for (auto neighbour : adj[u]) {
            int v = neighbour.first;
            int v_w = neighbour.second;

            if (!visited[v]) {
                pq.push({v, v_w});
            }
        }
    }

    cout << cost << endl;
}

int main() {
    vector<vector<pair<int,int>>> adj(6);

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

    prims(adj); // Output: 16

    return 0;
}

