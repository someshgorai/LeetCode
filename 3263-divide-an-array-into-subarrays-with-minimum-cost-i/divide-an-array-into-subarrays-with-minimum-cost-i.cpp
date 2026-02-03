class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int mini = 1e9, n = nums.size();
        for (int i = 1; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (mini > nums[i] + nums[j]) {
                    mini = nums[i] + nums[j];
                }
            }
        }
        return nums[0] + mini;
    }
};