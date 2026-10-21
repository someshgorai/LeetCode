class Solution {
private:
    long long backtrack(int idx, int n, int k, int transactionType, vector<int>& prices, vector<vector<vector<long long>>>& dp) {
        if (k == 0) {
            return 0;
        }
        if (idx == n) {
            if (transactionType != 0) {
                return -1e9;
            }
            return 0;
        }

        if (dp[idx][k][transactionType] != -1e18) return dp[idx][k][transactionType];

        long long buy = -1e9, sell = -1e9, skip = 1e9;
        if (transactionType == 0) {
            buy  = backtrack(idx + 1, n, k, 1, prices, dp) - prices[idx];
            sell = backtrack(idx + 1, n, k, 2, prices, dp) + prices[idx];
        }
        else if (transactionType == 1) {
            sell = backtrack(idx + 1, n, k - 1, 0, prices, dp) + prices[idx];
        }
        else {
            buy  = backtrack(idx + 1, n, k - 1, 0, prices, dp) - prices[idx];
        }

        skip = backtrack(idx + 1, n, k, transactionType, prices, dp);

        return dp[idx][k][transactionType] = max({buy, sell, skip});
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(k + 1, vector<long long> (3, 0)));

        for (int j = 0; j <= k; j++) {
            dp[n][j][1] = dp[n][j][2] = -1e18;
        }

        for (int idx = n-1; idx >= 0; idx--) {
            for (int j = 1; j <= k; j++) {
                for (int transactionType = 2; transactionType >= 0; transactionType--) {
                    long long buy = -1e9, sell = -1e9, skip = 1e9;
                    if (transactionType == 0) {
                        buy  = dp[idx+1][j][1] - prices[idx];
                        sell = dp[idx+1][j][2] + prices[idx];
                    }
                    else if (transactionType == 1) {
                        sell = dp[idx+1][j-1][0] + prices[idx];
                    }
                    else {
                        buy  = dp[idx+1][j-1][0] - prices[idx];
                    }

                    skip = dp[idx+1][j][transactionType];

                    dp[idx][j][transactionType] = max({buy, sell, skip});
                }
            }
        }
        return dp[0][k][0];
    }
};