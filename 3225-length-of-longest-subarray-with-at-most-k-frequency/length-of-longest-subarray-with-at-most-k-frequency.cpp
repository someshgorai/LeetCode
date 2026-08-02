class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        unordered_map<int, int> freq;

        int maxLen = 1;
        while (right < n) {
            freq[nums[right]]++;
            while (left < right && freq[nums[right]] > k){
                freq[nums[left]]--;
                left++;
            }
            int len = right - left + 1;
            maxLen = max(maxLen, len);
            right++;
        }

        return maxLen;
    }
};