class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(k + 1, vector<long long> (3, 0)));

        for (int j = 0; j <= k; j++) {
            dp[1][j][1] = dp[1][j][2] = -1e18;
        }

        for (int idx = n-1; idx >= 0; idx--) {
            for (int j = 1; j <= k; j++) {
                for (int transactionType = 2; transactionType >= 0; transactionType--) {
                    long long buy = -1e9, sell = -1e9, skip = 1e9;
                    if (transactionType == 0) {
                        buy  = dp[1][j][1] - prices[idx];
                        sell = dp[1][j][2] + prices[idx];
                    }
                    else if (transactionType == 1) {
                        sell = dp[1][j-1][0] + prices[idx];
                    }
                    else {
                        buy  = dp[1][j-1][0] - prices[idx];
                    }

                    skip = dp[1][j][transactionType];

                    dp[0][j][transactionType] = max({buy, sell, skip});
                }
            }
            swap(dp[0], dp[1]);
        }
        return dp[1][k][0];
    }
};