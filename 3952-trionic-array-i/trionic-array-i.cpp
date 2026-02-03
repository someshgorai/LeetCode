class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 0, n = nums.size();
        while (i < n-1 && nums[i] < nums[i+1]) i++;
        int p = i;
        while (i < n-1 && nums[i] > nums[i+1]) i++;
        int q = i;
        while (i < n-1 && nums[i] < nums[i+1]) i++;
        if (i != n-1) return false;
        if (p == 0 || p == q || q == n-1) return false;
        return true;
    }
};