class Solution {
private:
    double func(vector<int>& nums, float d) {
        double sum = 0;
        for (float i : nums) {
            sum += ceil (i/d);
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int high = *max_element(nums.begin(), nums.end());
        int low = 0;
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