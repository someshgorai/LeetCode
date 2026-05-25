class Solution {
private:
    int getJumps(int idx, vector<int>& nums, int d, int n, vector<int>& dp) {
        if (dp[idx] != -1) return dp[idx];

        int maxJumps = 1;
        for (int x = 1; x <= d; x++) {
            if (idx + x < n && nums[idx] > nums[idx + x]) {
                maxJumps = max(maxJumps, 1+getJumps(idx+x, nums, d, n, dp));
            }
            else break;
        }

        for (int x = 1; x <= d; x++) {
            if (idx - x >= 0 && nums[idx] > nums[idx - x]) {
                maxJumps = max(maxJumps, 1+getJumps(idx-x, nums, d, n, dp));
            }
            else break;
        }

        return dp[idx] = maxJumps;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        
        int maxTowers = 0;
        for (int i = 0; i < n; i++) {
            maxTowers = max(maxTowers, getJumps(i, arr, d, n, dp));
        }

        return maxTowers;
    }
};