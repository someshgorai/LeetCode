class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid[0].size(), m = grid.size();
        deque<pair<int, int>> dq;

        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));

        if (grid[0][0] == 1) {
            if (health == 1) return false;
            dq.push_back({0, 0});
            cost[0][0] = 1;
        }
        else {
            dq.push_front({0, 0});
            cost[0][0] = 0;
        }

        int drow[4] = {1, 0, -1, 0};
        int dcol[4] = {0, 1, 0, -1};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            if (x == m-1 && y == n-1 && cost[x][y] < health) return true;

            for (int i = 0; i < 4; i++) {
                int r = x + drow[i];
                int c = y + dcol[i];

                if (r >= 0 && r < m && c >= 0 && c < n) {
                    int h = cost[x][y] + grid[r][c];
                    if (h < cost[r][c]) {
                        if (cost[x][y]) dq.push_back({r, c});
                        else dq.push_front({r, c});
                        cost[r][c] = h;
                    }
                }
            }
        }

        return false;
    }
};