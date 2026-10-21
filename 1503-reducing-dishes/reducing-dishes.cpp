class Solution {
private: 
    int backtrack(int idx, int n, int time, vector<int>& satisfaction, vector<vector<int>>& dp) {
        if (idx == n) {
            return 0;
        }

        if (dp[idx][time] != -1e9) return dp[idx][time];

        int take = satisfaction[idx] * time + backtrack(idx + 1, n, time + 1, satisfaction, dp);
        int notTake = backtrack(idx + 1, n, time, satisfaction, dp);

        return dp[idx][time] = max(take, notTake);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n, vector<int>(n+1, -1e9));
        return backtrack(0, n, 1, satisfaction, dp);
    }
};