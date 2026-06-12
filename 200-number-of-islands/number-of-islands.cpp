class Solution {
private:
    int drow[4] = {1, 0, -1, 0};
    int dcol[4] = {0, 1, 0, -1};
    void traversal(int i, int j, int m, int n, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.emplace(i, j);
        vis[i][j] = true;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = x + drow[i];
                int c = y + dcol[i];

                if (r >= 0 && c >= 0 && r < m && c < n && grid[r][c] == '1' && !vis[r][c]) {
                    q.emplace(r, c);
                    vis[r][c] = true;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        int island = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    island++;
                    traversal(i, j, m, n, vis, grid);
                }
            }
        }

        return island;
    }
};