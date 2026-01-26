#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<int> run_bellman_ford(vector<vector<pair<int, int>>> &adj, int start = 0)
{
    int n = adj.size();
    vector<int> dist(n, 1e9);

    dist[start] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int u = 0; u < n; u++)
        {
            if (dist[u] == 1e9) continue;

            for (auto edge : adj[u])
            {
                int v = edge.first;
                int w = edge.second;

                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    for (int u = 0; u < n; u++)
    {
        if (dist[u] == 1e9) continue;

        for (auto edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v])
            {
                cout << "Graph contains a negative weight cycle\n";
                return {};
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " : " << dist[i] << endl;
    }

    return dist;
}

int main()
{
    vector<vector<pair<int,int>>> adj(5);

    adj[0].push_back({1, 6});
    adj[0].push_back({2, 7});

    adj[1].push_back({2, 8});
    adj[1].push_back({3, 5});
    adj[1].push_back({4, -4});

    adj[2].push_back({3, -3});
    adj[2].push_back({4, 9});

    adj[3].push_back({1, -2});

    adj[4].push_back({0, 2});
    adj[4].push_back({3, 7});


    run_bellman_ford(adj);

    return 0;
}