class Solution {
private:
    bool func(vector<int>& nums, int d, int threshold) {
        int sum = 0;
        for (int i : nums) {
            sum += (i + d - 1)/d;
            if (sum > threshold) return false;
        }
        return true;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int high = *max_element(nums.begin(), nums.end());
        int low = 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (func(nums, mid, threshold)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};