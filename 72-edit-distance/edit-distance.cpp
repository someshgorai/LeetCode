class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(2, vector<int>(m+1, 0));

        for (int j = 1; j <= m; j++) dp[0][j] = j;
        

        for (int i = 1; i <= n; i++) {
            dp[1][0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i-1] == word2[j-1]) dp[1][j] = dp[0][j-1];
                else dp[1][j] = min({
                    dp[0][j],
                    dp[1][j-1],
                    dp[0][j-1]
                }) + 1;
            }
            swap(dp[0], dp[1]);
        }
        return dp[0][m];
    }
};