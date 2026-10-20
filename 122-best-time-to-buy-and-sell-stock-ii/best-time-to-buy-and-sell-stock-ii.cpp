class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(2, 0));

        for (int i = n-1; i >= 0; i--) {
            for (int isHold = 0; isHold < 2; isHold++) {
                int buy = 0, sell = 0;
                if (isHold == 1) {
                    sell = prices[i] + dp[1][0];
                }
                else {
                    buy = -prices[i] + dp[1][1];
                }

                int skip = dp[1][isHold];

                dp[0][isHold] = max({buy, sell, skip});
            }
            swap(dp[0], dp[1]);
        }

        return dp[1][0];
    }
};