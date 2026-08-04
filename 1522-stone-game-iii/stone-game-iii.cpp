class Solution {
private:
    int backtrack(int i, int n, vector<int> &stoneValue, vector<int> &dp) {
        if (i >= n) return 0;

        if (dp[i] != -1e9) return dp[i];

        int stones = 0;
        int maxScore = -1e9;
        for (int j = 0; (j < 3) && (i + j < n); j++) {
            stones += stoneValue[i+j];
            maxScore = max(maxScore, stones - backtrack(i+j+1, n, stoneValue, dp));
        }

        return dp[i] = maxScore;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, -1e9);
        int diff = backtrack(0, n, stoneValue, dp);
    
        if (diff > 0) return "Alice";
        else if (diff < 0) return "Bob";
        return "Tie";
    }
};