class Solution {
private:
    int getLastOpsIdx(vector<int> &nums, vector<long long> &prefix, int i, int k) {
        if (i == 0) return i;

        int low = 0, high = i - 1;

        while (low <= high) {
            int mid = (high - low)/2 + low;

            long long costOps = (1LL)*(i - mid + 1)*nums[i] - (prefix[i] - prefix[mid] + nums[mid]);

            if (costOps <= k) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n, 0);

        sort(nums.begin(), nums.end());
        prefix[0] = nums[0];

        int maxFreq = 1;
        for (int i = 0; i < n; i++) {
            if (i > 0) prefix[i] = (1LL)*nums[i] + prefix[i-1];

            int lastOpsIdx = getLastOpsIdx(nums, prefix, i, k);

            maxFreq = max(maxFreq, i - lastOpsIdx + 1);
        }

        return maxFreq;
    }
};