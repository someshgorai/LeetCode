class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int sum = 0;
        int minLen = 1e9;
        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (l <= r && sum >= target) {
                minLen = min(minLen, r - l + 1);

                sum -= nums[l];
                l++;
            }
        }

        return minLen == 1e9 ? 0 : minLen;
    }
};