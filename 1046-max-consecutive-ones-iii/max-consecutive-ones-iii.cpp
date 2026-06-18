class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, maxLen = 0, zeros;
        while (r < n) {
            if (nums[r] == 0) zeros++;
            if (zeros > k) {
                if (nums[l] == 0) zeros--;
                l++;
            }
            if (zeros <= k) maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};