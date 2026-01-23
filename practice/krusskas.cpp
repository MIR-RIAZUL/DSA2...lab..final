#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge
{
    int u,v,weight;
};

bool compare(edge a,edge b)
{
    return a.weight<b.weight;
}
vector<int>parents;
vector<int>ranks;

void make_set(int vertex)
{
    parents[vertex]=vertex;
    ranks[vertex]=0;
}

int find_set(int vertex)
{
    if(parents[vertex]==vertex)
    return parents[vertex];
    return parents[vertex]=find_set(parents[vertex]);
}

void union_set(int vert_a,int vert_b)
{
    int parent_a=find_set(vert_a);
    int parent_b=find_set(vert_b);
    if(parent_a!=parent_b)
    {
        if(ranks[parent_a]<ranks[parent_b])
        {
            swap(parent_a,parent_b);
        }
        parents[parent_b]=parent_a;

        if(ranks[parent_a]==ranks[parent_b])
        {
            ranks[parent_a]++;
        }
    }

}


int main()
{

    int n=4;
    vector<edge>edges= {
        {1,2,10},
        {1,3,6},
        {1,4,5},
        {2,4,15},
        {3,4,4}
    };
    parents.resize(n+1);
    ranks.resize(n+1);

    sort(edges.begin(),edges.end(),compare);

    for (int i=1;i<=n;i++)
    {
        make_set(i);
    }

    int mst_weight=0;


    

    cout<<"edge in the minimum spaning tree:\n";

    for(auto edge :edges)
    {
        if(find_set(edge.u)!=find_set(edge.v))
        {
            cout<<edge.u<<"---"<<edge.v<<"(weight "<<edge.weight<<")\n";
            mst_weight+=edge.weight;
            union_set(edge.u,edge.v);
        }

    }
 cout<<"total wweight of the tree: "<<mst_weight<<endl;

return 0;
}