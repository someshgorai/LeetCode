class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakPoint = -1;
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                breakPoint = i;
                break;
            }
        }
        if (breakPoint != -1) {
            int next = INT_MAX;
            int nextIdx;
            for (int i = breakPoint+1; i < n; i++) {
                if (nums[breakPoint] < nums[i] && next > nums[i]) {
                    nextIdx = i;
                    next = nums[i];
                }
            }
            swap(nums[breakPoint], nums[nextIdx]);
            sort(nums.begin() + breakPoint + 1, nums.end());
        }
        else reverse(nums.begin(), nums.end());
        
    }
};