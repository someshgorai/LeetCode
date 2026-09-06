class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> dp(m+1, 0);
        
        dp[m] = 1;

        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                double take = 0;
                if (s[i] == t[j]) {
                    take = dp[j+1];
                }
                double notTake = dp[j];

                dp[j] = take + notTake;
            }
        }

        return dp[0];
    }
};