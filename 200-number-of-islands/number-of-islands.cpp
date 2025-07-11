#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>>& grid, vector<vector<bool>> &vis, pair<int, int>& a)
{
    queue<pair<int, int>> q;
    q.push(a);
    vis[a.first][a.second] = true;

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if (i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == '1')
        {
            q.push({i-1, j});
            vis[i-1][j] = true;
        }
        if (i+1 < grid.size() && !vis[i+1][j] && grid[i+1][j] == '1')
        {
            q.push({i+1, j});
            vis[i+1][j] = true;
        }
        if (j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == '1')
        {
            q.push({i, j-1});
            vis[i][j-1] = true;
        }
        if (j+1 < grid[0].size() && !vis[i][j+1] && grid[i][j+1] == '1')
        {
            q.push({i, j+1});
            vis[i][j+1] = true;
        }
    }
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        vector<pair<int, int>> vec;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    vec.push_back({i,j});
                }
            }
        }

        vector<vector<bool>> vis(m, vector<bool> (n, false));

        int count = 0;

        for (int i = 0; i < vec.size(); i++)
        {
            if (!vis[vec[i].first][vec[i].second])
            {
                bfs(grid, vis, vec[i]);
                count++;
            }
        }

        return count;
    }
};