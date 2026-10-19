class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, freq = 0;
        for (int i : nums) {
            if (i == target) freq++;
            if (i < target)  left++;
        }
        vector<int> ans;
        for (int i = left; i < left + freq; i++) ans.push_back(i);
        return ans;
    }
};