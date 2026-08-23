class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            int ways = 0;

            if (i >= 1) ways = dp[i-1];
            if (i >= 2) ways += dp[i-2];

            dp[i] = ways;
        }

        return dp[n];
    }
};