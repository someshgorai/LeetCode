class Solution {
private:
    int maxKadane(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int maxSum = -1e9;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            maxSum = max(sum, maxSum);

            if (sum < 0) {
                sum = 0;
            }
        }

        return maxSum;
    }
    int minKadane(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int minSum = 1e9;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            minSum = min(sum, minSum);

            if (sum > 0) {
                sum = 0;
            }
        }

        return minSum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        int nonCycle = maxKadane(nums);
        if (nonCycle < 0) return nonCycle;

        int cycle = (int)total - minKadane(nums);
        return max(cycle, nonCycle);
    }
};