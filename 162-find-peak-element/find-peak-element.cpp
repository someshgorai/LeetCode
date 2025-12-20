class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int low = 1, high = n-2;
        if (nums[low-1] > nums[low]) return 0;
        if (nums[high+1] > nums[high]) return n-1;

        while (low <= high) {
            long long mid = (high+low)/2;

            if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) {
                return mid;
            }
            else if (nums[mid] < nums[mid-1]) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return -1;
    }
};