#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void prims(vector<vector<pair<int,int>>> &adj)
{
    int n = adj.size();
    vector<bool> visited(n, false);


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    pq.push({0, 0});
    int cost = 0;

    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        int w=node.first;
        int u=node.second;

        if (visited[u]) continue;

        visited[u] = true;
        cost += w;

        for (auto nodes : adj[u])
        {
            int v=nodes.first;
            int vw=nodes.second;


            if (!visited[v])
                pq.push({vw, v});
        }
    }

    cout << cost << endl;
}

int main()
{
    vector<vector<pair<int,int>>> adj(6);

    adj[0].push_back({1,4});
    adj[1].push_back({0,4});

    adj[0].push_back({2,4});
    adj[2].push_back({0,4});

    adj[1].push_back({2,2});
    adj[2].push_back({1,2});

    adj[1].push_back({3,5});
    adj[3].push_back({1,5});

    adj[2].push_back({3,5});
    adj[3].push_back({2,5});

    adj[2].push_back({4,11});
    adj[4].push_back({2,11});

    adj[3].push_back({4,2});
    adj[4].push_back({3,2});

    adj[3].push_back({5,6});
    adj[5].push_back({3,6});

    adj[4].push_back({5,3});
    adj[5].push_back({4,3});

    prims(adj);
}
