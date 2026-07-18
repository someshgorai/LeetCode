class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> dp(m+1, 0);
        int dia, temp;

        for (int i = 1; i <= n; i++) {
            dia = dp[0];
            for (int j = 1; j <= m; j++) {
                temp = dp[j];
                if (word1[i-1] == word2[j-1]) dp[j] = dia + 1;
                else dp[j] = max(dp[j], dp[j-1]);
                dia = temp;
            }
        }

        return n + m - 2 * dp[m];
    }
};