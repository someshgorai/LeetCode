class Solution {
private:
    int backtrack(int i, int action, int n, vector<int> &prices, vector<vector<int>> &dp) {
        if (i >= n) {
            return 0;
        }

        if (dp[i][action] != -1) return dp[i][action];
        
        int profit = 0;
        if (action == 0) {
            profit = max(
                backtrack(i+1, 1, n, prices, dp) - prices[i],
                backtrack(i+1, action, n, prices, dp)
            );
        }
        else {
            profit = max(
                prices[i] + backtrack(i+1, 0, n, prices, dp),
                backtrack(i+1, action, n, prices, dp)
            );
        }

        return dp[i][action] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return backtrack(0, 0, n, prices, dp);
    }
};