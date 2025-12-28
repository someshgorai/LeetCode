class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLen = 1;
        vector<int> len(n, 1);
        for (int i=0; i<n; i++) {
            for (int k=0; k<i; k++) {
                if (nums[i] > nums[k]) {
                    len[i] = max(1+len[k], len[i]);
                }
            }
            maxLen = max(maxLen, len[i]);
        }
        return maxLen;
    }
};