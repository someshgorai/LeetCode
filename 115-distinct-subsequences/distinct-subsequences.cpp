class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n+1, vector<double> (m+1, 0));
        
        for (int i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                double take = 0;
                if (s[i] == t[j]) {
                    take = dp[i+1][j+1];
                }
                double notTake = dp[i+1][j];

                dp[i][j] = take + notTake;
            }
        }

        return dp[0][0];
    }
};