class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>> (2, vector<int>(3, 0)));
        for (int idx = n-1; idx >= 0; idx--) {
            for (int isHold = 0; isHold < 2; isHold++) {
                for (int limit = 2; limit >= 0; limit--) {

                    int buy = 0, sell = 0, skip = 0;
                    if (limit > 0 && !isHold) buy = dp[1][1][limit - 1] - prices[idx];
                    if (isHold) sell = dp[1][0][limit] + prices[idx];
                    skip = dp[1][isHold][limit];

                    dp[0][isHold][limit] = max({skip, buy, sell});
                }
            }
            swap(dp[0], dp[1]);
        }
        return dp[1][0][2];
    }
};