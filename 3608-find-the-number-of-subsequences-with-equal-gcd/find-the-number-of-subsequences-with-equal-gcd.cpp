class Solution {
private:   
    int mod = 1e9+7;
    int backtrack(int idx, int gcd1, int gcd2, int n, vector<int> &nums, vector<vector<vector<int>>> &dp) {
        // Base Case
        if (idx >= n) {
            if (gcd1 == 0 && gcd2 == 0) return 0;
            return gcd1 == gcd2;
        }

        if (dp[idx][gcd1][gcd2] != -1) return dp[idx][gcd1][gcd2];

        int take1, take2, notTake;
        if (gcd1 == 0) {
            take1 = backtrack(idx+1, nums[idx], gcd2, n, nums, dp);
        }
        else take1 = backtrack(idx+1, __gcd(gcd1, nums[idx]), gcd2, n, nums, dp);

        if (gcd2 == 0) {
            take2 = backtrack(idx+1, gcd1, nums[idx], n, nums, dp);
        }
        else take2 = backtrack(idx+1, gcd1, __gcd(gcd2, nums[idx]), n, nums, dp);

        notTake = backtrack(idx+1, gcd1, gcd2, n, nums, dp);

        return dp[idx][gcd1][gcd2] = ((take1+take2) % mod +notTake) % mod;
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(201, vector<int>(201, -1)));
        return backtrack(0, 0, 0, n, nums, dp);
    }
};