#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int minimumEffortPath(vector<vector<int>>& heights)
{
    int rows = heights.size();
    int cols = heights[0].size();

    vector<vector<int>> dist(rows, vector<int>(cols, 1e9));

    
    priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>
    > pq;

    dist[0][0] = 0;
    pq.push({0, {0, 0}});

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();

        int effort = node.first;
        int r = node.second.first;
        int c = node.second.second;

        if (effort > dist[r][c])
            continue;

        if (r == rows - 1 && c == cols - 1)
            return effort;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols)
            {
                int edge_cost = abs(heights[r][c] - heights[nr][nc]);
                int new_effort = max(dist[r][c], edge_cost);

                if (new_effort < dist[nr][nc])
                {
                    dist[nr][nc] = new_effort;
                    pq.push({new_effort, {nr, nc}});
                }
            }
        }
    }

    return 0;
}

int main()
{
    vector<vector<int>> heights = {
        {1,2,1,1,1},
        {1,2,1,2,1},
        {1,2,1,2,1},
        {1,2,1,2,1},
        {1,1,1,2,1}
    };

    cout << minimumEffortPath(heights) << endl;
}
