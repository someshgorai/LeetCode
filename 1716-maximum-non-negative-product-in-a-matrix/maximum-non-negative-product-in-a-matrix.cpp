class Solution {
private:
    vector<vector<pair<long long, long long>>> dp;

    pair<long long, long long> solve(int i, int j, int m, int n, vector<vector<int>>& grid) {
        // Base case
        if (i == m-1 && j == n-1) {
            return {grid[i][j], grid[i][j]};
        }

        if (dp[i][j].first != LLONG_MIN) return dp[i][j];

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        // Move Down
        if (i + 1 < m) {
            auto down = solve(i+1, j, m, n, grid);

            long long a = down.first * grid[i][j];
            long long b = down.second * grid[i][j];

            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        // Move Right
        if (j + 1 < n) {
            auto right = solve(i, j+1, m, n, grid);

            long long a = right.first * grid[i][j];
            long long b = right.second * grid[i][j];

            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        return dp[i][j] = {maxi, mini};
    }

public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dp.assign(m, vector<pair<long long, long long>>(n, {LLONG_MIN, LLONG_MIN}));

        auto res = solve(0, 0, m, n, grid);

        if (res.first < 0) return -1;
        return res.first % 1000000007;
    }
};