class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid[0].size(), m = grid.size();
        queue<pair<int, int>> q;

        vector<vector<int>> cost(m, vector<int>(n, -1));

        if (grid[0][0] == 1) {
            if (health == 1) return false;
            q.push({0, 0});
            cost[0][0] = 1;
        }
        else {
            q.push({0, 0});
            cost[0][0] = 0;
        }

        int drow[4] = {1, 0, -1, 0};
        int dcol[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == m-1 && y == n-1 && cost[x][y] < health) return true;

            for (int i = 0; i < 4; i++) {
                int r = x + drow[i];
                int c = y + dcol[i];

                if (r >= 0 && r < m && c >= 0 && c < n) {
                    int h = cost[x][y] + grid[r][c];
                    if (cost[r][c] == -1 || h < cost[r][c]) {
                        q.push({r, c});
                        cost[r][c] = h;
                    }
                }
            }
        }

        return false;
    }
};