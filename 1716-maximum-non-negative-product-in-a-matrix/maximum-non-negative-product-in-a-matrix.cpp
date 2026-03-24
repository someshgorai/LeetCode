class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int MOD = 1e9 + 7;

        vector<pair<long long,long long>> dp(n);

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {

                // Base case
                if (i == m-1 && j == n-1) {
                    dp[j] = {grid[i][j], grid[i][j]};
                    continue;
                }

                long long maxi = LLONG_MIN;
                long long mini = LLONG_MAX;

                // Down → dp[j] (old value)
                if (i + 1 < m) {
                    auto down = dp[j];

                    long long a = grid[i][j] * down.first;
                    long long b = grid[i][j] * down.second;

                    maxi = max({maxi, a, b});
                    mini = min({mini, a, b});
                }

                // Right → dp[j+1] (already updated)
                if (j + 1 < n) {
                    auto right = dp[j+1];

                    long long a = grid[i][j] * right.first;
                    long long b = grid[i][j] * right.second;

                    maxi = max({maxi, a, b});
                    mini = min({mini, a, b});
                }

                dp[j] = {maxi, mini};
            }
        }

        long long res = dp[0].first;

        if (res < 0) return -1;
        return res % MOD;
    }
};