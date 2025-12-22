class Solution {
private:
    int func(vector<int>& nums, int d) {
        int sum = 0;
        for (int i : nums) {
            sum += (i + d - 1)/d;
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int high = *max_element(nums.begin(), nums.end());
        int low = 1;
        while (low <= high) {
            long long mid = (low+high)/2;

            if (func(nums, mid) <= threshold) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};