class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLen = 1;
        vector<int> seq;
        seq.push_back(nums[0]);
        for (int i=1; i<n; i++) {
            if (nums[i] > seq.back()) {
                seq.push_back(nums[i]);
                maxLen++;
            }
            else {
                int idx = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                seq[idx] = nums[i];
            }
        }
        return maxLen;
    }
};