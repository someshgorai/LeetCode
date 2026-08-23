class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n+1, false);
        
        dp[n] = true;

        for (int idx = n-2; idx >= 0; idx--) {
            bool cond1 = false;
            bool cond2 = false;
            bool cond3 = false;

            if (idx + 1 < n && nums[idx] == nums[idx+1]) {
                cond1 = dp[idx+2];
            }

            if (idx + 2 < n && idx + 1 < n && nums[idx] == nums[idx+1] && nums[idx+1] == nums[idx+2]) {
                cond2 = dp[idx+3];
            }

            if (idx + 2 < n && idx + 1 < n && nums[idx] == nums[idx+1] - 1 && nums[idx+1] == nums[idx+2] - 1) {
                cond3 = dp[idx+3];
            }

            dp[idx] = cond1 || cond2 || cond3;
        }
        return dp[0];
    }
};