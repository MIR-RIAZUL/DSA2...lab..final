#include <iostream>
#include <vector>

using namespace std;

int cheapestFlight_BellmanFord(int n, vector<vector<int>>& flights,
                               int src, int dst, int k)
{
    vector<int> dist(n, 1e9);
    dist[src] = 0;

    for(int i = 0; i <= k; i++) {
        vector<int> temp = dist;

        for(auto &f : flights) {
            int u = f[0];
            int v = f[1];
            int wt = f[2];

            if(dist[u] != 1e9 && dist[u] + wt < temp[v]) {
                temp[v] = dist[u] + wt;
            }
        }
        dist = temp;
    }

    return dist[dst] == 1e9 ? -1 : dist[dst];
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

    cout << cheapestFlight_BellmanFord(n, flights, src, dst, k) << endl;

    return 0;
}
