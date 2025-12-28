class Solution {
private:
    int backtrack(int idx, int prev, vector<int> &nums, int n, vector<vector<int>> &dp) {
        if (idx == n) return 0;

        if (dp[idx][prev+1] != -1) return dp[idx][prev+1];
        int take = 0;
        if (prev == -1 || nums[idx] > nums[prev]) {
            take = 1 + backtrack(idx+1, idx, nums, n, dp);
        }
        int notTake = 0 + backtrack(idx+1, prev, nums, n, dp);

        return dp[idx][prev+1] = max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1));
        for (int idx=n-1; idx>=0; idx--) {
            for (int prev=idx-1; prev>=-1; prev--) {
                int take = 0;
                if (prev == -1 || nums[idx] > nums[prev]) {
                    take = 1 + dp[idx+1][idx+1];
                }
                int notTake = 0 + dp[idx+1][prev+1];

                dp[idx][prev+1] = max(take, notTake);                
            }
        }
        return dp[0][-1+1];
    }
};