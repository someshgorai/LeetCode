class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int l = 0;

        int target = accumulate(nums.begin(), nums.end(), 0LL) - x;
        
        if (target == 0) return n;

        int sum = 0;
        int maxLen = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (l <= r && sum > target) {
                sum -= nums[l];
                l++;
            }
            if (sum == target) {
                maxLen = max(maxLen, r - l + 1);
            }
        }

        return maxLen == 0 ? -1 : n - maxLen;
    }
};