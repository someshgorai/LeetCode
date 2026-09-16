class Solution {
private:
    int mod = 1e9+7;
    int backtrack(int i, int d, int n, int k, vector<vector<int>>& dp) {
        if (d == k) return 1;
        if (i >= n) return 0;

        if (dp[i][d] != -1) return dp[i][d];

        int take = 0;
        for (int s = i+1; s < n - (k - d - 1); s++) {
            take = (backtrack(s, d+1, n, k, dp) + take) % mod;
        }
        int notTake = backtrack(i+1, d, n, k, dp);

        return dp[i][d] = (take + notTake) % mod;
    }
public:
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(n, vector<int> (k, -1));
        return backtrack(0, 0, n, k, dp);
    }
};