class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);

        dp[n-1] = 0;

        for (int num = n-2; num >= 0; num--) {
            int minjumps = INT_MAX;
            for (int i = num + 1; i <= min(n-1 ,num + nums[num]); i++) {
                int nextjump = dp[i];
                if (nextjump != INT_MAX) {
                    minjumps = min(minjumps, dp[i] + 1);
                }
            }
            dp[num] = minjumps;
        }
        return dp[0];
    }
};