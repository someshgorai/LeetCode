class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid[0].size(), m = grid.size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        queue<pair<int, int>> q;
        int cntFresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                    vis[i][j] = true;
                }
                else if (grid[i][j] == 1) {
                    cntFresh++;
                }
            }
        }

        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, -1, 0, 1};
        int time = 0;
        while (!q.empty()) {
            int limit = q.size();

            while (limit--) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int r = x + drow[i];
                    int c = y + dcol[i];
                    if (r >= 0 && c >= 0 && r < m && c < n && grid[r][c] == 1 && !vis[r][c]) {
                        q.emplace(r, c);
                        vis[r][c] = true;
                        cntFresh--;
                    }
                }
            }
            if (!q.empty())time++;
        }

        if (cntFresh) return -1;
        return time;
    }
};