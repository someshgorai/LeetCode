class Solution {
public:
    int mod = 1e9+7;
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(m+1, vector<int>(m+1, 0)));
        
        for (int gcd = 1; gcd < m+1; gcd++) {
            dp[1][gcd][gcd] = 1;
        }

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int g1 = 0; g1 <= m; g1++) {
                for (int g2 = 0; g2 <= m; g2++) {

                    int ng1 = (g1 == 0) ? nums[idx] : gcd(g1, nums[idx]);
                    int ng2 = (g2 == 0) ? nums[idx] : gcd(g2, nums[idx]);

                    long long take1 = dp[1][ng1][g2];
                    long long take2 = dp[1][g1][ng2];
                    long long notTake = dp[1][g1][g2];

                    dp[0][g1][g2] =
                        (take1 + take2 + notTake) % mod;
                }
            }
            swap(dp[0], dp[1]);
        }

        return dp[1][0][0];
    }
};