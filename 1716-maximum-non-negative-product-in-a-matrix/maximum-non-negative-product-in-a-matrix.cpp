class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int MOD = 1e9 + 7;

        vector<vector<pair<long long,long long>>> dp(m, vector<pair<long long,long long>>(n));

        // Base case
        dp[m-1][n-1] = {grid[m-1][n-1], grid[m-1][n-1]};

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {

                if (i == m-1 && j == n-1) continue;

                long long maxi = LLONG_MIN;
                long long mini = LLONG_MAX;

                // Down
                if (i + 1 < m) {
                    auto down = dp[i+1][j];

                    long long a = grid[i][j] * down.first;
                    long long b = grid[i][j] * down.second;

                    maxi = max({maxi, a, b});
                    mini = min({mini, a, b});
                }

                // Right
                if (j + 1 < n) {
                    auto right = dp[i][j+1];

                    long long a = grid[i][j] * right.first;
                    long long b = grid[i][j] * right.second;

                    maxi = max({maxi, a, b});
                    mini = min({mini, a, b});
                }

                dp[i][j] = {maxi, mini};
            }
        }

        long long res = dp[0][0].first;

        if (res < 0) return -1;
        return res % MOD;
    }
};