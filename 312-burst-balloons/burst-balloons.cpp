class Solution {
private:
    int backtrack(int l, int r, vector<int> &nums, vector<vector<int>> &dp) {
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int maxCoins = 0;
        for (int i = l; i <= r; i++) {
            int coins = nums[l-1] * nums[i] * nums[r+1] + 
                backtrack(l, i-1, nums, dp) + backtrack(i+1, r, nums, dp);
            maxCoins = max(maxCoins, coins);
        }

        return dp[l][r] = maxCoins;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        return backtrack(1, n-2, nums, dp);
    }
};