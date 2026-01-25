class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;
        sort(nums.begin(), nums.end());
        int left = 0, right = k-1, minDiff = INT_MAX, n = nums.size();
        while (right < n) {
            minDiff = min (minDiff, nums[right] - nums[left]);
            right++;
            left++;
        }
        return minDiff;
    }
};