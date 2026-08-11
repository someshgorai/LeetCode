class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int prefixSum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1] + 1) {
                prefixSum += nums[i];
            }
            else break;
        }

        sort(nums.begin(), nums.end());
        auto it = lower_bound(nums.begin(), nums.end(), prefixSum) - nums.begin();

        while(it < n && nums[it] == prefixSum) {
            prefixSum++;
            it = lower_bound(nums.begin(), nums.end(), prefixSum) - nums.begin();
        }

        return prefixSum;
    }
};