class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n  = nums.size(), maxi = 1;
        vector<int> dp(n, 1), cnt(n, 1);
        for (int i=0; i<n; i++) {
            for (int prev=0; prev<i; prev++) {
                if (nums[i] > nums[prev]) {
                    if (dp[i] < dp[prev] + 1) {
                        dp[i] = dp[prev] + 1;
                        cnt[i] = cnt[prev];
                    }
                    else if (dp[i] == dp[prev] + 1) {
                        cnt[i] += cnt[prev];
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int nos = 0;
        for (int i=0; i<n; i++) {
            if (dp[i] == maxi) nos += cnt[i];
        }
        return nos;
    }
};