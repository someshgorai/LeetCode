class Solution {
private:
    int backtrack(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        // base case
        if (idx == 0) {
            if (amount%coins[idx] == 0) return 1;
            return 0;
        } 

        if (dp[idx][amount] != -1) return dp[idx][amount];

        int notTake = backtrack(idx-1, amount, coins, dp);
        int take = 0;
        if (amount >= coins[idx]) take = backtrack(idx, amount - coins[idx], coins, dp);

        return dp[idx][amount] = notTake + take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return backtrack(n-1, amount, coins, dp);
    }
};