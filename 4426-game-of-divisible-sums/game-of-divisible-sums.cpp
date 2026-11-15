class Solution {
private:
    long long backtrack(int idx, int n, vector<int>& nums, vector<long long>& dp) {
        if (idx >= n) return 0;

        if (dp[idx] != -1) return dp[idx];

        long long take1, sum1 = nums[idx];
        if (sum1 % 3 == 0) {
            take1 = sum1 - backtrack(idx + 1, n, nums, dp);
        }
        else {
            take1 = sum1 + backtrack(idx + 1, n, nums, dp);
        }

        long long take2 = -1e18;
        if (idx + 1 < n) {
            long long sum2 = nums[idx] + nums[idx + 1];
            if (sum2 % 3 == 0) {
                take2 = sum2 - backtrack(idx + 2, n, nums, dp);
            }
            else {
                take2 = sum2 + backtrack(idx + 2, n, nums, dp);
            }
        }

        return dp[idx] = max(take1, take2);
    }
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n, -1);
        return backtrack(0, n, nums, dp);
    }
};