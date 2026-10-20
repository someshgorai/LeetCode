class Solution {
private:    
    int backtrack(int i, int n, bool isHold, vector<int>& prices, vector<vector<int>>& dp) {
        if (i == n) {
            return 0;
        }

        if (dp[i][isHold] != -1) return dp[i][isHold];

        int buy = 0, sell = 0;
        if (isHold) {
            sell = prices[i] + backtrack(i+1, n, false, prices, dp);
        }
        else {
            buy = -prices[i] + backtrack(i+1, n, true, prices, dp);
        }

        int skip = backtrack(i+1, n, isHold, prices, dp);

        return dp[i][isHold] = max({buy, sell, skip});
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return backtrack(0, n, false, prices, dp);
    }
};