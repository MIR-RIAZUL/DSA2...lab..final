#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>run_dijkstras(vector<vector<pair<int,int>>>&adj,int start=0)
{

    int n= adj.size();
    vector<int>dist(n,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>>pq;
    dist[start]=0;
    pq.push({start,0});


    while(!pq.empty()){
    auto node=pq.top();
    pq.pop();
    int u=node.first;
    int d=node.second;

    if(d>dist[u]){
        continue;
    }

    for(auto neighbours: adj[u]){
        int v=neighbours.first;
        int v_d= neighbours.second;

        int new_dist= dist[u]+v_d;

        if(new_dist<dist[v]){
            dist[v]=new_dist;
            pq.push({v,dist[v]});
        }
    }
}
int i=0;
for(auto d:dist){
    cout<<i<<" :"<<endl;
    i++;
}
}



int main(){
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

     run_dijkstras(adj);

}
