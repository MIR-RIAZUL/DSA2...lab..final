#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> run_dijkstra(vector<vector<pair<int,int>>>& adj, int start)
{
    int n = adj.size();              

    
    vector<int> dist(n, 1e9);
    dist[start] = 0;

    
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, start});

 
    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int d = top.first;   
        int u = top.second;

        
        if(d > dist[u])
            continue;

        
        for(auto edge : adj[u])
        {
            int v = edge.first;   
            int w = edge.second;  

            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    int n = 3;
    int source = 0;
    int destination = 2;

  
    vector<vector<pair<int,int>>> adj(n);

    
    adj[0].push_back({1, 1});
    adj[1].push_back({0, 1});

    adj[1].push_back({2, 1});
    adj[2].push_back({1, 1});

    adj[2].push_back({0, 1});
    adj[0].push_back({2, 1});

  
    vector<int> dist = run_dijkstra(adj, source);

   
    if(dist[destination] != 1e9)
        cout << "true";
    else
        cout << "false";

    return 0;
}