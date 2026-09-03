class Solution {
private:
    bool isZeroArray(int k, vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n, 0);

        for (int i = 0; i <= k; i++) {
            auto& query = queries[i];

            int start = query[0];
            int end   = query[1];
            int val   = query[2];

            diff[start] += val;
            if (end + 1 < n) diff[end + 1] -= val;
        }

        for (int i = 1; i < n; i++) {
            diff[i] = diff[i] + diff[i-1];
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > diff[i]) return false;
        }

        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size();
        int low = 0, high = q - 1;
        
        bool isZero = true;
        for (int num : nums) {
            if (num != 0) isZero = false;
        }
        if (isZero) return 0;

        while (low <= high) {
            int mid = (high - low)/2 + low;

            if (isZeroArray(mid, nums, queries)) high = mid - 1;
            else low = mid + 1;
        }

        return low == q ? -1 : low+1;
    }
};