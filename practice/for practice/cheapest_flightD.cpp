#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int run_dijkstras(vector<vector<pair<int,int>>>& adj,
                  int src, int dst, int k)
{
    int n = adj.size();

    // dist[node][stops] = min cost
    vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

    priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
    > pq;

    // {cost, node, stops}
    dist[src][0] = 0;
    pq.push({0, src, 0});

    while(!pq.empty())
    {
        auto node = pq.top();
        pq.pop();

        int cost  = node[0];
        int u     = node[1];
        int stops = node[2];

        if (u == dst)
            return cost;

        if (stops > k)
            continue;

        for (auto neighbours : adj[u])
        {
            int v   = neighbours.first;
            int w   = neighbours.second;

            int new_cost = cost + w;

            if (new_cost < dist[v][stops + 1])
            {
                dist[v][stops + 1] = new_cost;
                pq.push({new_cost, v, stops + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int n = 4;
    vector<vector<pair<int,int>>> adj(n);

    // flights: u -> v (cost)
    adj[0].push_back({1, 100});
    adj[1].push_back({2, 100});
    adj[2].push_back({3, 100});
    adj[0].push_back({2, 500});

    int src = 0;
    int dst = 3;
    int k   = 1;

    int ans = run_dijkstras(adj, src, dst, k);

    if(ans == -1)
        cout << "No route found" << endl;
    else
        cout << "Cheapest price: " << ans << endl;

    return 0;
}
