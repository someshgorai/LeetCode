class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int subArr = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == target) count++;
                if (count > (j - i + 1)/2) subArr++;
            }
        }
        return subArr;
    }
};