class Solution {
public:
    int ans = 0;
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, visited, rows, cols, i, j);
                    ans++;
                }
            }
        }
        return ans;        
    }

    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int rows, int cols, int i, int j){
        if(i < 0 || j < 0 || i >= rows || j >= cols || visited[i][j] || grid[i][j] != '1'){
            return;
        }

        visited[i][j] = true;
        dfs(grid, visited, rows, cols, i + 1, j);
        dfs(grid, visited, rows, cols, i - 1, j);
        dfs(grid, visited, rows, cols, i, j + 1);
        dfs(grid, visited, rows, cols, i, j - 1);
    }
};