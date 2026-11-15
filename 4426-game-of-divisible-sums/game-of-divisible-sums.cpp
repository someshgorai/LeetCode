class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        long long prev1 = 0, prev2 = 0;

        for (int idx = n - 1; idx >= 0; idx--) {
            long long take1, sum1 = nums[idx];
            if (sum1 % 3 == 0) {
                take1 = sum1 - prev1;
            }
            else {
                take1 = sum1 + prev1;
            }

            long long take2 = -1e18;
            if (idx + 1 < n) {
                long long sum2 = nums[idx] + nums[idx + 1];
                if (sum2 % 3 == 0) {
                    take2 = sum2 - prev2;
                }
                else {
                    take2 = sum2 + prev2;
                }
            }
            prev2 = prev1;
            prev1 = max(take1, take2);
        } 
        return prev1;
    }
};