class Solution {
private:
    vector<vector<bool>> getPalindromes(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool> (n, false));

        for (int l = 1; l <= n; l++) {
            for (int i = 0; i + l <= n; i++) {
                int j = i + l - 1;

                if (i == j) {
                    isPalindrome[i][j] = true;
                }
                else if (i + 1 == j) {
                    isPalindrome[i][j] = (s[i] == s[j]);
                }
                else {
                    isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i+1][j-1];
                }
            }
        }

        return isPalindrome;
    }
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1) return n;
        vector<int> dp(n+1, 0);

        vector<vector<bool>> isPalindrome = getPalindromes(s);

        for (int i = n - 1; i >= 0; i--) {
            int take = 0;
            for (int j = i + k - 1; j < n; j++) {
                if (isPalindrome[i][j]) {
                    take = max(take, 1 + dp[j+1]);
                }
            }
            
            int skip = dp[i+1];

            dp[i] = max(take, skip);
        }
        return dp[0];
    }
};