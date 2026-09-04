class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxeles(n, nums[0]), mineles(n, nums[n-1]);
        for (int i = 1; i < n; i++) {
            maxeles[i] = max(nums[i], maxeles[i-1]);
        }
        for (int j = n-2; j >= 0; j--) {
            mineles[j] = min(nums[j], mineles[j+1]);
        }
        int stable = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (maxeles[i] - mineles[i] <= k) stable = min(i, stable);
        }

        if (stable == INT_MAX) return -1;
        return stable;
    }
};