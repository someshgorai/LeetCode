class Solution {
private:
    int backtrack(int idx, int n, vector<int>& costs, vector<int>& dp) {
        if (idx == n) {
            return 0;
        }

        if (dp[idx] != -1) return dp[idx];

        int minCost = 1e9;
        
        minCost = min(minCost, backtrack(idx + 1, n, costs, dp) + costs[idx + 1 - 1] + 1);

        if (idx + 2 <= n) {
            minCost = min(minCost, backtrack(idx + 2, n, costs, dp) + costs[idx + 2 - 1] + 4);
        }

        if (idx + 3 <= n) {
            minCost = min(minCost, backtrack(idx + 3, n, costs, dp) + costs[idx + 3 - 1] + 9);
        } 

        return dp[idx] = minCost;
    }
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1);

        for (int idx = n - 1; idx >= 0; idx--) {
            int minCost = 1e9;
        
            minCost = min(minCost, dp[idx + 1] + costs[idx + 1 - 1] + 1);

            if (idx + 2 <= n) {
                minCost = min(minCost, dp[idx + 2] + costs[idx + 2 - 1] + 4);
            }

            if (idx + 3 <= n) {
                minCost = min(minCost, dp[idx + 3] + costs[idx + 3 - 1] + 9);
            } 

            dp[idx] = minCost;
        }
        return backtrack(0, n, costs, dp);
    }
};