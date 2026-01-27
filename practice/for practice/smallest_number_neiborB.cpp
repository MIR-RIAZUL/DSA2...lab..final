#include <iostream>
#include <vector>

using namespace std;


int findTheCity(int n, vector<vector<pair<int,int>>> &adj, int distanceThreshold)
{
    int answer = -1;
    int minCount = 1e9;

    
    for(int start = 0; start < n; start++)
    {
        vector<int> dist(n, 1e9);
        dist[start] = 0;

       
        for(int i = 0; i < n - 1; i++)
        {
            for(int u = 0; u < n; u++)
            {
                if(dist[u] == 1e9) continue;

                for(auto edge : adj[u])
                {
                    int v = edge.first;
                    int w = edge.second;

                    if(dist[u] + w < dist[v])
                    {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }

        
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(i != start && dist[i] <= distanceThreshold)
                count++;
        }

        // smallest count, tie -> largest city index
        if(count <= minCount)
        {
            minCount = count;
            answer = start;
        }
    }

    return answer;
}

int main()
{
    int n = 4;
    int distanceThreshold = 4;

    // adjacency list
    vector<vector<pair<int,int>>> adj(n);

    // add undirected edges
    adj[0].push_back({1,3});
    adj[1].push_back({0,3});

    adj[1].push_back({2,1});
    adj[2].push_back({1,1});

    adj[1].push_back({3,4});
    adj[3].push_back({1,4});

    adj[2].push_back({3,1});
    adj[3].push_back({2,1});

    cout << findTheCity(n, adj, distanceThreshold) << endl;

    return 0;
}
