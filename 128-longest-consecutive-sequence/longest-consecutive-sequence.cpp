class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());

        int lastSmallest = INT_MIN;
        int maxLen = 1, len = 1;

        for (int i : nums) {
            if (i-1 == lastSmallest) {
                len++;
            }
            else if (i != lastSmallest){
                len = 1;
            }
            maxLen = max(len, maxLen);
            lastSmallest = i;
        }

        return maxLen;
    }
};