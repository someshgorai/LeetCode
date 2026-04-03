class Solution {
private:
    int backtrack(int i, int j, int life, int m, int n, vector<vector<int>>& coins, vector<vector<vector<int>>> &dp) {
        if (i >= m || j >= n) return -1e9;

        // Base Case
        if (i == m - 1 && j == n - 1){
            if (coins[i][j] < 0 && life > 0) return 0;
            return coins[i][j];
        }

        if (dp[i][j][life] != -1e9) return dp[i][j][life];

        int val = coins[i][j];

        // move options
        int right = backtrack(i, j + 1, life, m, n, coins, dp);
        int down  = backtrack(i + 1, j, life, m, n, coins, dp);

        int bestNext = max(right, down);

        // Option 1: take current cell
        int take = val + bestNext;

        // Option 2: skip negative (if allowed)
        int skip = -1e9;
        if (val < 0 && life > 0) {
            int r = backtrack(i, j + 1, life - 1, m, n, coins, dp);
            int d = backtrack(i + 1, j, life - 1, m, n, coins, dp);
            skip = max(r, d);
        }

        return dp[i][j][life] = max(take, skip);
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(3, -1e9)));
        
        dp[m-1][n-1][0] = coins[m-1][n-1];
        if (coins[m-1][n-1] < 0) {
            dp[m-1][n-1][1] = dp[m-1][n-1][2] = 0;
        }
        else {
            dp[m-1][n-1][1] = dp[m-1][n-1][2] = coins[m-1][n-1];
        }

        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                for (int life = 2; life >= 0; life--) {
                    if (i == m - 1 && j == n - 1) continue;
                    int val = coins[i][j];

                    // move options
                    int right = dp[i][j+1][life];
                    int down  = dp[i+1][j][life];

                    int bestNext = max(right, down);

                    // Option 1: take current cell
                    int take = val + bestNext;

                    // Option 2: skip negative (if allowed)
                    int skip = -1e9;
                    if (val < 0 && life > 0) {
                        int r = dp[i][j+1][life-1];
                        int d = dp[i+1][j][life-1];
                        skip = max(r, d);
                    }

                    dp[i][j][life] = max(take, skip);
                }
            }
        }

        return dp[0][0][2];
    }
};