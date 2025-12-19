class Solution {
private:
    int lowerBound(int low, int high, vector<int>& nums, int target) {
        while (low <= high) {
            int mid = (high - low)/2 + low;

            if (nums[mid] >= target) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
    int upperBound(int low, int high, vector<int>& nums, int target) {
        while (low <= high) {
            int mid = (high - low)/2 + low;

            if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int lower = lowerBound(0, n-1, nums, target);
        int upper = upperBound(0, n-1, nums, target)-1;
        if (lower == n || nums[lower] != target) return {-1, -1};

        return {lower, upper};
    }
};