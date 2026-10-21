class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(2, vector<int>(n+2, 0));

        for (int idx = n-1; idx >= 0; idx--) {
            for (int time = n; time >= 1; time--) {
                int take = satisfaction[idx] * time + dp[1][time + 1];
                int notTake = dp[1][time];

                dp[0][time] = max(take, notTake);
            }
            swap(dp[0], dp[1]);
        }
        return dp[1][1];
    }
};