class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);

        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[0] = 1;
                    continue;
                }
                int paths = 0;
                if (i-1 >= 0) {
                    paths += dp[j];
                }
                if (j-1 >= 0) {
                    paths += temp[j-1];
                }

                temp[j] = paths;
            }
            dp = temp;
        }

        return dp[n-1];
    }
};