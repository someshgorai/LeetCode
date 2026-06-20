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
            for (int i = n-1; i > breakPoint; i--) {
                if (nums[breakPoint] < nums[i]) {
                    swap(nums[breakPoint], nums[i]);
                    break;
                }
            }
        }
        reverse(nums.begin() + breakPoint + 1, nums.end());
    }
};