#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;
vector<int> ranks;

void make_set(int vertex)
{
    parents[vertex] = vertex;
    ranks[vertex] = 0;
}

int find_set(int vertex)
{
    if (vertex == parents[vertex])
        return parents[vertex];
    return parents[vertex] = find_set(parents[vertex]);
}

void union_sets(int vert_a, int vert_b)
{
    int parent_a = find_set(vert_a);
    int parent_b = find_set(vert_b);
    if (parent_a != parent_b)
    {
        if (ranks[parent_a] < ranks[parent_b])
        {
            swap(parent_a, parent_b);
        }
        parents[parent_b] = parent_a;
        if (ranks[parent_a] == ranks[parent_b])
        {
            ranks[parent_a]++;
        }
    }
}

int main()
{
    vector<int> nodes = {1, 2, 3, 4};
    parents = vector<int>(nodes.size());
    ranks = vector<int>(nodes.size());
    for (int i : nodes)
    {
        make_set(i);
    }
    int search_key = 2;
    cout << "For search key " << search_key << ", the parent is " << find_set(search_key) << " before union sets\n";
    union_sets(nodes[0], nodes[1]);
    cout << "For search key " << search_key << ", the parent is " << find_set(search_key) << " after union sets\n";
    search_key = 3;
    cout << "For search key " << search_key << ", the parent is " << find_set(search_key) << " before union sets\n";
    union_sets(nodes[2], nodes[1]);
    cout << "For search key " << search_key << ", the parent is " << find_set(search_key) << " after union sets\n";
}
