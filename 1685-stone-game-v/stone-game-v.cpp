class Solution {
private:
    int backtrack(int left, int right, vector<int> &prefix, vector<vector<int>> & dp) {
        if (left == right) {
            return 0;
        }

        if(dp[left][right] != -1) return dp[left][right];

        int maxScore = 0;
        for (int i = left; i <= right; i++) {
            int leftSum  = prefix[i+1] - prefix[left];
            int rightSum = prefix[right+1] - prefix[i+1];

            if (leftSum > rightSum) {
                maxScore = max(maxScore, rightSum + backtrack(i+1, right, prefix, dp));
            }
            else if (rightSum > leftSum) {
                maxScore = max(maxScore, leftSum + backtrack(left, i, prefix, dp));
            }
            else {
                maxScore = max({
                    maxScore, 
                    leftSum + backtrack(left, i, prefix, dp),
                    rightSum + backtrack(i+1, right, prefix, dp)
                });
            }
        }

        return dp[left][right] = maxScore;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = stoneValue[i] + prefix[i];
        }

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        return backtrack(0, n-1, prefix, dp);
    }
};