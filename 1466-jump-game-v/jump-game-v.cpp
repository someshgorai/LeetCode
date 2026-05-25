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
        vector<int> dp(n, 0);

        vector<pair<int, int>> locus;

        for (int i = 0; i < n; i++) {
            locus.push_back({arr[i], i});
        }
        
        sort(locus.begin(), locus.end());

        int maxTowers = 0;
        for (auto it : locus) {
            auto [height, idx] = it;

            int towers = 1;
            for (int x = 1; x <= d; x++) {
                if (idx + x < n && arr[idx] > arr[idx + x]) {
                    towers = max(towers, 1+ dp[idx+x]);
                }
                else break;
            }

            for (int x = 1; x <= d; x++) {
                if (idx - x >= 0 && arr[idx] > arr[idx - x]) {
                    towers = max(towers, 1+ dp[idx-x]);
                }
                else break;
            }

            dp[idx] = towers;

            maxTowers = max(maxTowers, towers);
        }

        return maxTowers;
    }
};