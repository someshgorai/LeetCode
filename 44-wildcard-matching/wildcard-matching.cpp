class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<bool> dp(m+1, false);

        dp[0] = true;
        for (int j = 1; j <= m; j++) {
            if (p[j-1] == '*')
                dp[j] = dp[j-1];
            else
                dp[j] = false;
        }

        bool dia, temp;

        for (int i = 1; i <= n; i++) {
            dia = dp[0];
            dp[0] = false;
            for (int j = 1; j <= m; j++) {
                temp = dp[j];
                if (s[i-1] == p[j-1]) dp[j] = dia;
                else {
                    if (p[j-1] == '?') dp[j] = dia;
                    else if (p[j-1] == '*') dp[j] = dia || dp[j-1] || dp[j];
                    else dp[j] = false;
                }
                dia = temp;
            }
        }

        return dp[m];
    }
};