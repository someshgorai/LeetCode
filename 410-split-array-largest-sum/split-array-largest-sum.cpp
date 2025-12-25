class Solution {
private:
    int partitions(vector<int>& nums, int maxSum) {
        int parts = 1;
        long long sum = 0;
        for (int i: nums) {
            if (sum + i <= maxSum) {
                sum += i;
            }
            else {
                parts++;
                sum = i;
            }
        }
        return parts;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0LL);
        while (low <= high) {
            int mid = (high - low)/2 +low;
            if (partitions(nums, mid) <= k) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};