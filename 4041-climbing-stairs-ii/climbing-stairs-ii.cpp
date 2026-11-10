class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(4);

        for (int idx = n - 1; idx >= 0; idx--) {
            int minCost = 1e9;
        
            minCost = min(minCost, dp[1] + costs[idx + 1 - 1] + 1);

            if (idx + 2 <= n) {
                minCost = min(minCost, dp[2] + costs[idx + 2 - 1] + 4);
            }

            if (idx + 3 <= n) {
                minCost = min(minCost, dp[3] + costs[idx + 3 - 1] + 9);
            } 

            dp[0] = minCost;
            dp[3] = dp[2];
            dp[2] = dp[1];
            dp[1] = dp[0];
        }
        return dp[0];
    }
};