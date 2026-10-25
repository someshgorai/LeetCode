class Solution {
private:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    void BFS(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        q.emplace(i, j);
        vis[i][j] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int r = x + drow[k];
                int c = y + dcol[k];

                if (r >= 0 && r < m && c >= 0 && c < n && !vis[r][c] && grid[r][c] == 0) {
                    q.emplace(r, c);
                    vis[r][c] = true;
                }
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        // 1. Mark the open islands
        // 2. Find no. of components

        int n = grid[0].size(), m = grid.size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0 && !vis[i][0]) BFS(i, 0, vis, grid);
            if (grid[i][n - 1] == 0 && !vis[i][n - 1]) BFS(i, n - 1, vis, grid); 
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0 && !vis[0][j]) BFS(0, j, vis, grid);
            if (grid[m-1][j] == 0 && !vis[m-1][j]) BFS(m-1, j, vis, grid);
        }
    
        int cnt = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    BFS(i, j, vis, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};