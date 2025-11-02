class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        // 0 = empty, 1 = wall, 2 = guard

        for (auto &w : walls)
            grid[w[0]][w[1]] = 1;
        for (auto &g : guards)
            grid[g[0]][g[1]] = 2;

        vector<vector<bool>> guarded(m, vector<bool>(n, false));

        // Left to Right
        for (int i = 0; i < m; i++) {
            bool seen = false;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) seen = false;      // wall
                else if (grid[i][j] == 2) seen = true;  // guard
                else if (seen) guarded[i][j] = true;
            }
        }

        // Right to Left
        for (int i = 0; i < m; i++) {
            bool seen = false;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) seen = false;
                else if (grid[i][j] == 2) seen = true;
                else if (seen) guarded[i][j] = true;
            }
        }

        // Top to Bottom
        for (int j = 0; j < n; j++) {
            bool seen = false;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 1) seen = false;
                else if (grid[i][j] == 2) seen = true;
                else if (seen) guarded[i][j] = true;
            }
        }

        // Bottom to Top
        for (int j = 0; j < n; j++) {
            bool seen = false;
            for (int i = m - 1; i >= 0; i--) {
                if (grid[i][j] == 1) seen = false;
                else if (grid[i][j] == 2) seen = true;
                else if (seen) guarded[i][j] = true;
            }
        }

        // Count unguarded empty cells
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !guarded[i][j])
                    count++;
            }
        }

        return count;
    }
};
