class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n + 1, vector<int>(n+2, 0));

        for (int idx = n-1; idx >= 0; idx--) {
            for (int time = n; time >= 1; time--) {
                int take = satisfaction[idx] * time + dp[idx + 1][time + 1];
                int notTake = dp[idx + 1][time];

                dp[idx][time] = max(take, notTake);
            }
        }
        return dp[0][1];
    }
};