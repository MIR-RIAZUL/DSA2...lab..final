#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parents;
vector<int> ranks;

struct Edge
{
    int u, v, weight;
};

void make_set(int vertex)
{
    parents[vertex] = vertex;
    ranks[vertex] = 0;
}

int find_set(int vertex)
{
    if (vertex == parents[vertex])
        return vertex;
    return parents[vertex] = find_set(parents[vertex]);
}

void union_sets(int vert_a, int vert_b)
{
    int parent_a = find_set(vert_a);
    int parent_b = find_set(vert_b);

    if (parent_a != parent_b)
    {
        if (ranks[parent_a] < ranks[parent_b])
            swap(parent_a, parent_b);

        parents[parent_b] = parent_a;

        if (ranks[parent_a] == ranks[parent_b])
            ranks[parent_a]++;
    }
}



int main()
{
    int n = 4;
    vector<Edge> edges = {
        {1, 2, 10},
        {1, 3, 6},
        {1, 4, 5},
        {2, 4, 15},
        {3, 4, 4}
    };

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    parents.resize(n + 1);
    ranks.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        make_set(i);
    }

    int mst_weight = 0;

    cout << "Edges in the Minimum Spanning Tree:\n";

    for (auto edge : edges)
    {
        if (find_set(edge.u) != find_set(edge.v))
        {
            cout << edge.u << " - " << edge.v<< " (weight " << edge.weight << ")\n";
            mst_weight += edge.weight;
            union_sets(edge.u, edge.v);
        }
    }
    cout << "Total weight of MST = " << mst_weight << endl;

    return 0;
}
