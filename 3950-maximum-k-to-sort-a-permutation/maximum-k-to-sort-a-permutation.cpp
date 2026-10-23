class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int bit_and = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                if (bit_and == -1) bit_and = nums[i];
                else bit_and &= nums[i];
            }
        }
        return bit_and == -1 ? 0 : bit_and;
    }
};