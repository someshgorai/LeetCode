class Solution {
private:
    int getGCD(int n, int m) {
        if (m == 0) return n;
        return gcd(m, n % m);
    }
    vector<vector<int>> getAllGCD(vector<int> &nums, int n) {
        vector<vector<int>> gcd(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            gcd[i][i] = nums[i];
            for (int j = i+1; j < n; j++) {
                gcd[i][j] = gcd[j][i] = getGCD(nums[i], nums[j]);
            }
        }

        return gcd;
    }
    int backtrack(int p, int n, vector<bool> &taken, vector<int> &nums, vector<vector<int>> &gcd, 
        unordered_map<vector<bool>, int> &dp) {
        if (p > n) {
            return 0;
        }

        if (dp.find(taken) != dp.end()) return dp[taken];

        int maxScore = 0;

        for (int i = 0; i < 2*n; i++) {
            if (taken[i] == true) continue;
            taken[i] = true;
            for (int j = i+1; j < 2*n; j++) {
                if (taken[j] == true) continue;
                taken[j] = true;
                maxScore = max(maxScore, p * gcd[i][j] + backtrack(p+1, n, taken, nums, gcd, dp));
                taken[j] = false;
            }
            taken[i] = false;
        }

        return dp[taken] = maxScore;
    }
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> taken(n, false);
        vector<vector<int>> gcd(n, vector<int>(n, 1));
        gcd = getAllGCD(nums, n); 
        unordered_map<vector<bool>, int> dp;
        return backtrack(1, n/2, taken, nums, gcd, dp);
    }
};