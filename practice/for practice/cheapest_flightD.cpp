#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cheapestFlight_Dijkstra(int n, vector<vector<int>>& flights,
                            int src, int dst, int k)
{
    vector<vector<pair<int,int>>> adj(n);
    for(auto &f : flights) {
        adj[f[0]].push_back({f[1], f[2]});
    }

    // (cost, node, stops)
    priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
    > pq;

    pq.push({0, src, 0});

    vector<vector<int>> best(n, vector<int>(k+2, 1e9));
    best[src][0] = 0;

    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        int cost = cur[0];
        int u = cur[1];
        int stops = cur[2];

        if(u == dst) return cost;
        if(stops > k) continue;

        for(auto nbr : adj[u]) {
            int v = nbr.first;
            int wt = nbr.second;

            if(cost + wt < best[v][stops+1]) {
                best[v][stops+1] = cost + wt;
                pq.push({cost + wt, v, stops + 1});
            }
        }
    }

    return -1;
}

int main() {
    int n = 4;
    vector<vector<int>> flights = {
        {0,1,100},
        {1,2,100},
        {2,0,100},
        {1,3,600},
        {2,3,200}
    };

    int src = 0;
    int dst = 3;
    int k = 1;

    cout << cheapestFlight_Dijkstra(n, flights, src, dst, k) << endl;

    return 0;
}
