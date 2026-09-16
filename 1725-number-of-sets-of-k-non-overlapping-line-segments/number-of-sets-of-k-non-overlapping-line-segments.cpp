class Solution {
private:
    int mod = 1e9+7;
public:
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(k+1, vector<int> (n+1, 0));

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 1;
        }

        for (int d = 1; d <= k; d++) {
            vector<int> prefix(n+1);
            for (int i = n-1; i >= 0; i--) {
                prefix[i] = (prefix[i+1] + dp[d-1][i]) % mod;
            }
            for (int i = n-1; i >= 0; i--) {
                int take = prefix[i+1] % mod;
                int notTake = dp[d][i+1];

                dp[d][i] = (take + notTake) % mod;
            }
        }

        return dp[k][0];
    }
};