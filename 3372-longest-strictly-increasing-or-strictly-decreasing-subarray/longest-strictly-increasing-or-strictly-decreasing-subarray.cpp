class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLen = 1, n = nums.size();

        if (n == 0) return 0;

        int incLeft = 0, decLeft = 0;
        for (int right = 1; right < n; right++) {
            if (nums[right - 1] >= nums[right]) {
                incLeft = right;
            }

            if (nums[right - 1] <= nums[right]) {
                decLeft = right;
            }

            maxLen = max({maxLen, right - incLeft + 1, right - decLeft + 1});
        }

        return maxLen;
    }
};