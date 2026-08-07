class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            else {
                nums[left] = nums[i];
                left++;
            }
        }

        for (int i = left; i < n; i++) {
            nums[i] = 0;
        }
    }
};