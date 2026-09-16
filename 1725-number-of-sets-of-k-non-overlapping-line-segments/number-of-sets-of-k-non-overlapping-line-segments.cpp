class Solution {
private:
    int mod = 1e9+7;
public:
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(2, vector<int> (n+1, 0));

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 1;
        }

        for (int d = 1; d <= k; d++) {
            vector<int> suffix(n+1);
            fill(dp[1].begin(), dp[1].end(), 0);
            for (int i = n-1; i >= 0; i--) {
                suffix[i] = (suffix[i+1] + dp[0][i]) % mod;
            }
            for (int i = n-1; i >= 0; i--) {
                int take = suffix[i+1] % mod;
                int notTake = dp[1][i+1];

                dp[1][i] = (take + notTake) % mod;
            }
            swap(dp[0], dp[1]);
        }

        return dp[0][0];
    }
};