#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int minimumEffortPath(vector<vector<int>> &heights) {
    int rows = heights.size();
    int cols = heights[0].size();
    int n = rows * cols; // total number of nodes

    // effort array (flattened)
    vector<int> dist(n, 1e9);

    // directions: up, down, left, right
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    // min-heap: {effort_so_far, node_index}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[0] = 0; // top-left cell
    pq.push({0, 0});

    while(!pq.empty()) {
        auto node = pq.top();
        pq.pop();
        int d = node.first;
        int idx = node.second;
        int r = idx / cols;
        int c = idx % cols;

        if(d > dist[idx]) continue;

        // explore neighbors
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                int nidx = nr * cols + nc;
                int edgeWeight = abs(heights[r][c] - heights[nr][nc]);
                int newDist = max(dist[idx], edgeWeight);
                if(newDist < dist[nidx]) {
                    dist[nidx] = newDist;
                    pq.push({newDist, nidx});
                }
            }
        }
    }

    return dist[n-1]; // bottom-right cell
}

int main() {
    vector<vector<int>> heights = {
        {1,2,2},
        {3,8,2},
        {5,3,5}
    };

    cout << minimumEffortPath(heights) << endl; // Output: 2

    return 0;
}
