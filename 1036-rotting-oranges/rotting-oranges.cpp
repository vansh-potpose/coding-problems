class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int minTime) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || (grid[i][j] > 1 && grid[i][j] < minTime))
            return;
        grid[i][j] = minTime;
        dfs(grid, i - 1, j, m, n, minTime + 1);
        dfs(grid, i + 1, j, m, n, minTime + 1);
        dfs(grid, i, j - 1, m, n, minTime + 1);
        dfs(grid, i, j + 1, m, n, minTime + 1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    dfs(grid, i, j, m, n, 2);
            }
        }
        int minutes = 2;
        for (auto& row : grid) {
            for (int cell : row) {
                if (cell == 1) return -1;
                minutes = max(minutes, cell);
            }
        }
        return minutes - 2;
    }
};