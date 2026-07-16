class Solution {
    int backtrack(int idx, int target, vector<int>&coins, vector<vector<int>> &dp) {
        if (idx < 0) {
            if (target == 0) return 0;
            return 1e9;
        }

        if (dp[idx+1][target] != -1) return dp[idx+1][target];

        int take = 1e9;
        if (target >= coins[idx]) take = backtrack(idx, target - coins[idx], coins, dp) + 1;
        int notTake = backtrack(idx-1, target, coins, dp);

        return dp[idx+1][target] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, 1e9));

        dp[0][0] = 0;

        for(int idx = 0; idx < n; idx++) {
            for (int target = 0; target <= amount; target++) {
                int take = 1e9;
                if (target >= coins[idx]) take = dp[idx+1][target - coins[idx]] + 1;
                int notTake = dp[idx][target];

                dp[idx+1][target] = min(take, notTake);
            }
        }

        int coin = dp[n][amount];
        if (coin == 1e9) return -1;
        return coin;
    }
};