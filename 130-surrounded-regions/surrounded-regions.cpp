class Solution {
private:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<bool>>& vis) {
        int m = board.size(), n = board[0].size();
        vis[r][c] = true;

        for (int k = 0; k < 4; k++) {
            int nr = r + drow[k];
            int nc = c + dcol[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                board[nr][nc] == 'O' && !vis[nr][nc]) {
                dfs(nr, nc, board, vis);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Top & bottom rows
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !vis[0][j])
                dfs(0, j, board, vis);
            if (board[m-1][j] == 'O' && !vis[m-1][j])
                dfs(m-1, j, board, vis);
        }

        // Left & right columns
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !vis[i][0])
                dfs(i, 0, board, vis);
            if (board[i][n-1] == 'O' && !vis[i][n-1])
                dfs(i, n-1, board, vis);
        }

        // Flip surrounded regions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
