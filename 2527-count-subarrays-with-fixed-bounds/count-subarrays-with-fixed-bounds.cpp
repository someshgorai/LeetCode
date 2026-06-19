class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long count = 0;
        int minIdx = -1;
        int maxIdx = -1;
        int cul = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] > maxK || nums[i] < minK) {
                cul = i;
            }
            if (nums[i] == minK) {
                minIdx = i;
            }
            if (nums[i] == maxK) {
                maxIdx = i;
            }
            long long temp = min(maxIdx, minIdx) - cul;
            if (temp > 0) {
                count += temp;
            }
        }

        return count;
    }
};