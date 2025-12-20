class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        int low = 1, high = n-2;
        if (nums[low] != nums[low-1]) return nums[low-1];
        if (nums[high] != nums[high+1]) return nums[high+1];

        while (low <= high) {
            int mid = (high+low)/2;

            if (nums[mid-1] == nums[mid]) {
                if (mid & 1) {
                    low = mid + 1;
                }
                else {
                    high = mid - 2;
                }
            }
            else if (nums[mid] == nums[mid+1]) {
                if (mid & 1) {
                    high = mid - 1;
                }
                else {
                    low = mid + 2;
                }
            }
            else {
                return nums[mid];
            }
        }
        return 0;
    }
};