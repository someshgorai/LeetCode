class Solution {
public:
    using PP = pair<int, pair<int, int>>;
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<PP, vector<PP>, greater<PP>> pq;
        vector<vector<int>> time(m, vector<int> (n, 1e9));

        pq.push({grid[0][0], {0, 0}});
        time[0][0] = grid[0][0];

        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [t, locus] = pq.top();
            auto [x, y] = locus;
            pq.pop();

            if (t > time[x][y]) continue;
            if (x == m-1 && y == n-1) return t;

            for (int i = 0; i < 4; i++) {
                int r = x + drow[i];
                int c = y + dcol[i];

                if (r < 0 || c < 0 || r >= m || c >= n) continue;
                
                int reqTime = max(t, grid[r][c]);
                if (reqTime < time[r][c]) {
                    time[r][c] = reqTime;
                    pq.push({reqTime, {r, c}});
                }
            }
        }

        return -1;
    }
};