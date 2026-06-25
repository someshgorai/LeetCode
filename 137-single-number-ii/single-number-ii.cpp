class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if (n == 1) return nums[0];

        for (int i = 1; i < n; i += 3) {
            if (nums[i-1] != nums[i]) return nums[i-1];
        }
        return nums[n-1];
    }
};