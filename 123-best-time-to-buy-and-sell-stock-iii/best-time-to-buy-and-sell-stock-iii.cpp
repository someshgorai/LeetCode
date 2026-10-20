class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(3, 0)));
        for (int idx = n-1; idx >= 0; idx--) {
            for (int isHold = 0; isHold < 2; isHold++) {
                for (int limit = 2; limit >= 0; limit--) {

                    int buy = 0, sell = 0, skip = 0;
                    if (limit > 0 && !isHold) buy = dp[idx + 1][1][limit - 1] - prices[idx];
                    if (isHold) sell = dp[idx + 1][0][limit] + prices[idx];
                    skip = dp[idx + 1][isHold][limit];

                    dp[idx][isHold][limit] = max({skip, buy, sell});
                }
            }
        }
        return dp[0][0][2];
    }
};