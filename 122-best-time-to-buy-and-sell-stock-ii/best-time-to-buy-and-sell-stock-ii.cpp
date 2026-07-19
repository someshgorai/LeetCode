class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for (int i = n-1; i >= 0; i--) {
            for (int action = 0; action < 2; action++) {
                int profit = 0;
                if (action == 0) {
                    profit = max(
                        dp[i+1][1] - prices[i],
                        dp[i+1][action]
                    );
                }
                else {
                    profit = max(
                        prices[i] + dp[i+1][0],
                        dp[i+1][action]
                    );
                }

                dp[i][action] = profit;                
            }
        }

        return dp[0][0];
    }
};