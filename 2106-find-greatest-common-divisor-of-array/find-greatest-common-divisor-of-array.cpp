class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0, mini = 1000;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        return __gcd(maxi, mini);
    }
};