class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return min(nums[0], nums[1]);

        int low = 0, high = n - 1, mid;
        while (low < high) {
            while (low < n - 1 && nums[low] == nums[low+1]) low++;
            while (high > 0 && nums[high] == nums[high-1]) high--;
            
            mid = (high - low)/2 + low;

            if (nums[mid] > nums[high]) low = mid + 1;
            else high = mid; 
        }
        return nums[low];
    }
};