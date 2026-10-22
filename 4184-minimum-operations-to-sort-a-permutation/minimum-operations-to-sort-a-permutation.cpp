class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                idx = i;
                break;
            }
        }

        bool isAsc = true;

        for (int i = 1; i < n; i++) {
            if (nums[(idx + i) % n] != i) {
                isAsc = false;
                break;
            }
        }

        bool isDesc = true;

        for (int i = 1; i < n; i++) {
            if (nums[(idx + i) % n] != n - i) {
                isDesc = false;
                break;
            }
        }

        if (!isAsc && !isDesc) {
            return -1;
        }

        int ans = INT_MAX;

        if (isAsc) {
            return min(idx, n - idx + 2);
        }
        if (isDesc) {
            return min(idx + 2, n - idx);
        }

        return -1;
    }
};