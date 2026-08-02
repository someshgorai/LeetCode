class Solution {
private:
    long long backtrack(vector<int> &nums, int left, int right, vector<vector<int>> &dp) {
        if (left > right) {
            return 0;
        }
        if (dp[left][right] != -1) return dp[left][right];

        long long take_left = nums[left] + min(
            backtrack(nums, left+2, right, dp),
            backtrack(nums, left+1, right-1, dp)
        );

        long long take_right = nums[right] + min(
            backtrack(nums, left+1, right-1, dp),
            backtrack(nums, left, right-2, dp)
        );

        return dp[left][right] = max(take_left, take_right);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        long long total = accumulate(nums.begin(), nums.end(), 0LL);

        long long score1 = backtrack(nums, 0, n-1, dp);

        long long score2 = total - score1;

        if (score1 >= score2) {
            return true;
        }

        return false;
    }
};