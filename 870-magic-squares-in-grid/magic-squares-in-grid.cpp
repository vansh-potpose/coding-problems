class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size(), ans = 0;
        if (r < 3 || c < 3) return 0;

        for (int i = 0; i + 2 < r; i++) {
            for (int j = 0; j + 2 < c; j++) {
                bool used[10] = {};
                bool ok = true;
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        int v = grid[i + x][j + y];
                        if (v < 1 || v > 9 || used[v]) {
                            ok = false;
                            break;
                        }
                        used[v] = true;
                    }
                    if (!ok) break;
                }
                if (!ok) continue;

                int s = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                for (int x = 0; x < 3; x++)
                    if (grid[i+x][j] + grid[i+x][j+1] + grid[i+x][j+2] != s) ok = false;
                for (int y = 0; y < 3; y++)
                    if (grid[i][j+y] + grid[i+1][j+y] + grid[i+2][j+y] != s) ok = false;
                if (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != s) ok = false;
                if (grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != s) ok = false;

                if (ok) ans++;
            }
        }
        return ans;
    }
};