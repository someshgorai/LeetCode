class Solution {
private:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    void bfs(queue<pair<int, int>> &q, vector<vector<bool>> &vis, vector<vector<int>>& grid, int m , int n) {
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int k=0; k<4; k++) {
                int r = row + drow[k];
                int c = col + dcol[k];
                if (r >= 0 && r < m && c >= 0 && c < n && !vis[r][c] && grid[row][col] == 1) {
                    q.emplace(r, c);
                    vis[r][c] = true;
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool> (n, false));

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i == 0 || i == m-1 || j == n-1 || j == 0 ) {
                    if (grid[i][j] == 1) {
                        q.emplace(i, j);
                        vis[i][j] = true;
                    }
                }
            }
        }

        bfs(q, vis, grid, m, n);

        int cnt = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};