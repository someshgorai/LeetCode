class Solution {
private:
    int backtrack(int i, int n, vector<int>& nums, vector<int> &dp) {
        // Base Case
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        int pick = nums[i] + backtrack(i+2, n, nums, dp);
        int notPick = backtrack(i+1, n, nums, dp);

        return dp[i] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return backtrack(0, n, nums, dp);
    }
};