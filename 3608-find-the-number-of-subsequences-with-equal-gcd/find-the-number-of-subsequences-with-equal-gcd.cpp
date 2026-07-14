class Solution {
public:
    int mod = 1e9+7;
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(m+1, 0)));
        
        for (int gcd = 1; gcd < m+1; gcd++) {
            dp[n][gcd][gcd] = 1;
        }

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int g1 = 0; g1 <= m; g1++) {
                for (int g2 = 0; g2 <= m; g2++) {

                    int ng1 = (g1 == 0) ? nums[idx] : gcd(g1, nums[idx]);
                    int ng2 = (g2 == 0) ? nums[idx] : gcd(g2, nums[idx]);

                    long long take1 = dp[idx + 1][ng1][g2];
                    long long take2 = dp[idx + 1][g1][ng2];
                    long long notTake = dp[idx + 1][g1][g2];

                    dp[idx][g1][g2] =
                        (take1 + take2 + notTake) % mod;
                }
            }
        }

        return dp[0][0][0];
    }
};