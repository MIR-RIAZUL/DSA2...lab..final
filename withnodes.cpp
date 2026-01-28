#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void run_dijkstras(vector<vector<pair<int, int>>> &adj, int start = 0)
{
    int n = adj.size();

    vector<int> dist(n, 1e9);
    vector<int> parent(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});   // (distance, node)

    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();

        int d = node.first;
        int u = node.second;

        if (d > dist[u])
            continue;

        for (auto neighbours : adj[u])
        {
            int v = neighbours.first;
            int w = neighbours.second;

            int new_dist = dist[u] + w;

            if (new_dist < dist[v])
            {
                dist[v] = new_dist;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // ---- print distances ----
    for (int i = 0; i < n; i++)
        cout << i << " : " << dist[i] << endl;

    // ---- print actual path (0 -> 5) ----
    int dest = 5;

    if (dist[dest] == 1e9)
    {
        cout << "No path\n";
        return;
    }

    vector<int> path;
    int cur = dest;

    while (cur != -1)
    {
        path.push_back(cur);
        cur = parent[cur];
    }

    cout << "Path: ";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;
}

int main()
{
    vector<vector<pair<int, int>>> adj(6);

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

    run_dijkstras(adj);

    return 0;
}
