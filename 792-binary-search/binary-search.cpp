class Solution {
private:
    int backtrack(int low, int high, vector<int>& nums, int target) {
        if (low > high) return -1;

        int mid = (high - low)/2 + low;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) return backtrack(low, mid-1, nums, target);
        return backtrack(mid+1, high, nums, target);
    }
public:
    int search(vector<int>& nums, int target) {
        return backtrack(0, nums.size()-1, nums, target);
    }
};