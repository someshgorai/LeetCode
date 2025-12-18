class Solution {
private:
    int backtrack(int target, int low, int high, vector<int> &arr) {
        //Base Case
        if (low > high) return low;
        long long mid = (low + high) / 2;
        if (arr[mid] >= target) return backtrack(target, low, mid-1, arr);
        return backtrack(target, mid+1, high, arr);
    } 
public:
    int searchInsert(vector<int>& nums, int target) {
        return backtrack(target, 0, nums.size()-1, nums);
    }
};