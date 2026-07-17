class Solution {
private:
    int backtrack(int i, int j, string s, string t, vector<vector<int>> &dp) {
        // Base Case
        if (i < 0 || j < 0) {
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = backtrack(i-1, j-1, s, t, dp) + 1;
        }
        return dp[i][j] = max(backtrack(i-1, j, s, t, dp), backtrack(i, j-1, s, t, dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = ""; 
        for (int i = n-1; i >= 0; i--) {
            t += s[i];
        }
        vector<vector<int>> dp(2, vector<int>(n+1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i] == t[j]) {
                    dp[1][j+1] = dp[0][j] + 1;
                }
                else dp[1][j+1] = max(dp[0][j+1], dp[1][j]);
            }
            swap(dp[1], dp[0]);
        }
        
        return dp[0][n];
    }
};