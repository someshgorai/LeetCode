class Solution {
private:
    bool isPalindrome(int start, int end, string& s) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    int backtrack(int i, string s, int k, int n, vector<int>& dp) {
        if (i >= n) return 0;

        if (dp[i] != -1) return dp[i];

        int take = 0;
        for (int j = i + k - 1; j < n; j++) {
            if (isPalindrome(i, j, s)) {
                take = max(take, 1 + backtrack(j+1, s, k, n, dp));
            }
        }
        
        int skip = backtrack(i+1, s, k, n, dp);

        return dp[i] = max(take, skip);
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1) return n;
        vector<int> dp(n, -1);
        return backtrack(0, s, k, n, dp);
    }
};