class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>&board, vector<vector<int>>&vis, int delrow[], int delcol[]){
        vis[r][c] = 1;
        for(int i=0;i<4;i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];

            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && board[nr][nc]=='O' && !vis[nr][nc]){
                dfs(nr, nc, board, vis, delrow, delcol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        vector<vector<int>>vis(n, vector<int>(m,0));
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i] == 'O') dfs(0,i,board,vis, delrow, delcol);
        }
        for(int i=0;i<m;i++){
            if(!vis[n-1][i] && board[n-1][i] == 'O') dfs(n-1,i,board,vis, delrow, delcol);
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0] == 'O') dfs(i,0,board,vis, delrow, delcol);
        }
        for(int i=0;i<n;i++){
            if(!vis[i][m-1] && board[i][m-1] == 'O') dfs(i,m-1,board,vis, delrow, delcol);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};