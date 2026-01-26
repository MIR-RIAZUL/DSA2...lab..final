#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int run_dijkstras(vector<vector<pair<int,int>>>& adj, int start)
{
    int n = adj.size();
    vector<int> dist(n, 1e9);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[start] = 0;
    pq.push({0, start}); // (distance, node)

    while(!pq.empty()) {
        auto node = pq.top();
        pq.pop();

        int d = node.first;
        int u = node.second;

        if(d > dist[u]) continue;

        for(auto neighbours : adj[u]) {
            int v = neighbours.first;
            int wt = neighbours.second;

            int new_dist = dist[u] + wt;

            if(new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }

    // Network Delay Time logic
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(dist[i] == 1e9) return -1;
        ans = max(ans, dist[i]);
    }

    return ans;
}
