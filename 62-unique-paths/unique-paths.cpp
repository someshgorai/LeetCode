class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);

        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int paths = 0;
                if (i-1 >= 0) {
                    paths += dp[j];
                }
                if (j-1 >= 0) {
                    paths += dp[j-1];
                }

                dp[j] = paths;
            }
        }

        return dp[n-1];
    }
};