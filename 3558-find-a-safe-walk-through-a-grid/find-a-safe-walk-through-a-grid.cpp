class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid[0].size(), m = grid.size();
        queue<pair<int, pair<int, int>>> q;

        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(health+1, false)));

        if (grid[0][0] == 1) {
            if (health == 1) return false;
            q.push({health - 1, {0, 0}});
            vis[0][0][health - 1] = true;
        }
        else {
            q.push({health, {0, 0}});
            vis[0][0][health] = true;
        }

        int drow[4] = {1, 0, -1, 0};
        int dcol[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [life, cell] = q.front();
            auto [x, y] = cell;
            q.pop();

            if (x == m-1 && y == n-1) return true;

            for (int i = 0; i < 4; i++) {
                int r = x + drow[i];
                int c = y + dcol[i];

                if (r >= 0 && r < m && c >= 0 && c < n && !vis[r][c][life] && grid[r][c] == 0) {
                    q.push({life, {r, c}});
                    vis[r][c][life] = true;
                }
            }

            if (life > 1) {
                for (int i = 0; i < 4; i++) {
                    int r = x + drow[i];
                    int c = y + dcol[i];

                    if (r >= 0 && r < m && c >= 0 && c < n && !vis[r][c][life-1] && grid[r][c] == 1) {
                        q.push({life - 1, {r, c}});
                        vis[r][c][life - 1] = true;
                    }
                }
            }
        }

        return false;
    }
};