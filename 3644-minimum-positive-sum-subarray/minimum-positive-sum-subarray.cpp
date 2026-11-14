class Solution {
    public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int sum = 0;
            int maxEnd = min(n - 1, i + r - 1);
            for (int j = i; j <= maxEnd; ++j) {
                sum += nums[j];
                if (j - i + 1 >= l && sum > 0) {
                    minSum = min(minSum, sum);
                }
            }
        }

        return minSum == INT_MAX ? -1 : minSum;
    }
};