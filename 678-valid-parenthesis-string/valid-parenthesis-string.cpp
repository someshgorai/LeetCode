class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        dp[n][0] = true;

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int cnt = n - 1; cnt >= 0; cnt--) {

                if (s[idx] == '(') {
                    dp[idx][cnt] = dp[idx + 1][cnt + 1];
                }
                else if (s[idx] == ')') {
                    if (cnt > 0)
                        dp[idx][cnt] = dp[idx + 1][cnt - 1];
                }
                else {
                    if (cnt + 1 <= n)
                        dp[idx][cnt] = dp[idx + 1][cnt + 1];

                    dp[idx][cnt] = dp[idx][cnt] || dp[idx + 1][cnt];

                    if (cnt > 0)
                        dp[idx][cnt] = dp[idx][cnt] || dp[idx + 1][cnt - 1];
                }
            }
        }

        return dp[0][0];
    }
};