class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(2, 0));

        for (int i = n-1; i >= 0; i--) {

            dp[0][0] = max(dp[1][1] - prices[i], dp[1][0]);
            dp[0][1] = max(prices[i] + dp[1][0], dp[1][1]);
            swap(dp[0], dp[1]);
        }

        return dp[1][0];
    }
};