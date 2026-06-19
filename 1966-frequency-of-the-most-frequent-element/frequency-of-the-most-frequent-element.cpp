class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0;
        int maxFreq = 1;
        long long sum = 0;

        for (int r = 0; r < n; r++) {
            sum += nums[r];
            long long opsCost = (1LL) * (r - l + 1) * nums[r] - sum;

            while (opsCost > k) {
                opsCost = opsCost - (nums[r] - nums[l]);
                sum = sum - nums[l];
                l++;
            }

            maxFreq = max(maxFreq, (r - l + 1));
        }

        return maxFreq;
    }
};