class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l1 = nums[n-1];
        int l2 = nums[n-2];
        int l3 = nums[n-3];
        int s1 = nums[0];
        int s2 = nums[1];

        return max(l1 * l2 * l3, s1 * s2 * l1);
    }
};