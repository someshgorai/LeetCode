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
        vector<int> dp(n + 1, -1);
        return backtrack(0, n, costs, dp);
    }
};