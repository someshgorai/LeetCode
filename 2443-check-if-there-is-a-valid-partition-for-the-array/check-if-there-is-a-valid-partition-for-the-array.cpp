class Solution {
private:
    bool backtrack(int idx, int n, vector<int> &nums, vector<int> &dp) {
        if (idx >= n) return true;

        bool cond1 = false;
        bool cond2 = false;
        bool cond3 = false;

        if (dp[idx] != -1) return dp[idx];

        if (idx + 1 < n && nums[idx] == nums[idx+1]) {
            cond1 = backtrack(idx+2, n, nums, dp);
        }

        if (idx + 2 < n && idx + 1 < n && nums[idx] == nums[idx+1] && nums[idx+1] == nums[idx+2]) {
            cond2 = backtrack(idx+3, n, nums, dp);
        }

        if (idx + 2 < n && idx + 1 < n && nums[idx] == nums[idx+1] - 1 && nums[idx+1] == nums[idx+2] - 1) {
            cond3 = backtrack(idx+3, n, nums, dp);
        }

        return dp[idx] = cond1 || cond2 || cond3;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return backtrack(0, n, nums, dp);
    }
};