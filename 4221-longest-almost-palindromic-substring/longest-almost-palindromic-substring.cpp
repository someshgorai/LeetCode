class Solution {
private:
    int backtrack(string &s, int i, int j, vector<vector<int>> &dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) return dp[i][j] = backtrack(s, i+1, j-1, dp);

        return dp[i][j] = 1 + min(backtrack(s, i+1, j, dp), backtrack(s, i, j-1, dp));
    }
public:
    int almostPalindromic(string s) {
        int n = s.size();
        int maxPalin = 2;
        vector<vector<int>> dp(n, vector<int> (n, -1));
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                int len = j - i + 1;
                if (len > 1 && backtrack(s, i, j, dp) <= 1) {
                    maxPalin = max(len, maxPalin);
                }
            }
        }
        return maxPalin;
    }
};