class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return true;

            // shrink duplicates aggressively
            while (l < m && nums[l] == nums[m]) l++;
            while (m < r && nums[r] == nums[m]) r--;

            if (nums[l] <= nums[m]) { // left sorted
                if (nums[l] <= target && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else { // right sorted
                if (nums[m] < target && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return false;
    }
};
