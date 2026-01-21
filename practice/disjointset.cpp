#include<iostream>
#include<vector>
using namespace std;

vector<int>parents;
vector<int>ranks;

void make_set(int vertex)
{
    parents[vertex]=vertex;
    ranks[vertex]=0;
}

int find_set(int vertex)
{
    if(vertex==parents[vertex])
        return parents[vertex];
    return parents[vertex]=find_set(parents[vertex]); 
}
void union_set(int vert_a,int vert_b)
{
    int parent_a=find_set(vert_a);
    int parent_b=find_set(vert_b);
    if(parent_a !=parent_b)
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
    vector<int>nodes;
    cout<<"enter the nodes number:";
    int n;
    cin>>n;


    for(int i=0;i<n;i++)
    {
         int x;
    cin >> x;
    nodes.push_back(x);
    }
    cout<<endl;

   parents=vector<int>(nodes.size()+1);
   ranks=vector<int>(nodes.size()+1);

   for(int i:nodes)
   {
    make_set(i);
   }

   int m;

   cout<<"how many operation you want to do:";
   cin>>m;

   for(int i=0;i<m;i++)
   {
    int k,l,b;
    cout<<"inter the search key:";
    cin>>k;
    int search_key = k;
    cout<<endl;
    cout<<"enter nodes to union:";
    cin>>l>>b;
    cout << "For search key " << search_key << ", the parent is " << find_set(search_key) << " before union sets\n";
    union_set(nodes[l],nodes[b]);
    cout << "For search key " << search_key << ", the parent is " << find_set(search_key) << " after union sets\n";
   }
    return 0;
}