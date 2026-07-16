class Solution {
    int backtrack(int idx, int target, vector<int>&coins, vector<vector<int>> &dp) {
        if (idx < 0) {
            if (target == 0) return 0;
            return 1e9;
        }

        if (dp[idx][target] != -1) return dp[idx][target];

        int take = 1e9;
        if (target >= coins[idx]) take = backtrack(idx, target - coins[idx], coins, dp) + 1;
        int notTake = backtrack(idx-1, target, coins, dp);

        return dp[idx][target] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int coin = backtrack(n-1, amount, coins, dp);
        if (coin == 1e9) return -1;
        return coin;
    }
};