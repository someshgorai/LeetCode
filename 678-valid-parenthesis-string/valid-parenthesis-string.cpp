class Solution {
private:
    int backtrack(int idx, int n, int cnt, string s, vector<vector<int>> &dp) {
        if (idx == n) return cnt == 0;
        if (cnt < 0) return false;
        
        if (dp[idx][cnt] != -1) return dp[idx][cnt];

        if (s[idx] == '(') return dp[idx][cnt] = backtrack(idx+1, n, cnt+1, s, dp);
        if (s[idx] == ')') return dp[idx][cnt] = backtrack(idx+1, n, cnt-1, s, dp);
        
        return dp[idx][cnt] = 
                backtrack(idx+1, n, cnt+1, s, dp) || 
                backtrack(idx+1, n, cnt-1, s, dp) ||
                backtrack(idx+1, n, cnt, s, dp);
    }
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return backtrack(0, n, 0, s, dp);
    }
};