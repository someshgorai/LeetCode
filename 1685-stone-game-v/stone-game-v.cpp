class Solution {
private:
    int backtrack(int left, int right, vector<int> &prefix, vector<vector<int>> & dp) {
        if (left == right) {
            return 0;
        }

        if(dp[left][right] != -1) return dp[left][right];

        int maxScore = 0;
        for (int i = left; i < right; i++) {
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

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int left = n-1; left >= 0; left--) {
            for (int right = left+1; right < n; right++) {
                int maxScore = 0;
                for (int i = left; i < right; i++) {
                    int leftSum  = prefix[i+1] - prefix[left];
                    int rightSum = prefix[right+1] - prefix[i+1];

                    if (leftSum > rightSum) {
                        maxScore = max(maxScore, rightSum + dp[i+1][right]);
                    }
                    else if (rightSum > leftSum) {
                        maxScore = max(maxScore, leftSum + dp[left][i]);
                    }
                    else {
                        maxScore = max({
                            maxScore, 
                            leftSum + dp[left][i],
                            rightSum + dp[i+1][right]
                        });
                    }
                }
                dp[left][right] = maxScore;
            }
        }

        return dp[0][n-1];
    }
};