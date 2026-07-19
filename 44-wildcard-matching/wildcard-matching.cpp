class Solution {
private:
    bool LCS(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if (i < 0 && j < 0) return true;
        if (i < 0) {
            while (j >= 0) {
                if (p[j] != '*') return false;
                j--;
            }
            return true;
        }
        if (i >= 0 && j < 0) return false;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j]) return dp[i][j] = LCS(i-1, j-1, s, p, dp);
        else {
            if (p[j] == '?') return dp[i][j] = LCS(i-1, j-1, s, p, dp);
            if (p[j] == '*') return dp[i][j] = LCS(i-1, j-1, s, p, dp) || LCS(i, j-1, s, p, dp) || LCS(i-1, j, s, p, dp);
        }
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return LCS(n-1, m-1, s, p, dp);
    }
};