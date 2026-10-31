class Solution {
private: 
    int mod = 1e9 + 7;
    int getValidPathsCount(int i, int j, int m, int n, int dir, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        // Base Case
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (dp[i][j][dir] != -1) return dp[i][j][dir];

        long long right = 0, down = 0;
        if (grid[i][j] == 0) {
            if (i + 1 < m) {
                down = getValidPathsCount(i + 1, j, m, n, 0, grid, dp);
            }
            if (j + 1 < n) {
                right = getValidPathsCount(i, j + 1, m, n, 1, grid, dp);
            }
        }
        else {
            if (dir == 0) {
                if (j + 1 < n) {
                    right = getValidPathsCount(i, j + 1, m, n, 1, grid, dp);
                }
            }
            else {
                if (i + 1 < m) {
                    down = getValidPathsCount(i + 1, j, m, n, 0, grid, dp);
                }
            }
        }


        return dp[i][j][dir] = (right + down) % mod;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));

        // Base Case
        dp[m-1][n-1][0] = dp[m - 1][n - 1][1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) continue;
                for (int dir = 0; dir < 2; dir++) {
                    long long right = 0, down = 0;
                    if (grid[i][j] == 0) {
                        if (i + 1 < m) {
                            down = dp[i + 1][j][0];
                        }
                        if (j + 1 < n) {
                            right = dp[i][j + 1][1];
                        }
                    }
                    else {
                        if (dir == 0) {
                            if (j + 1 < n) {
                                right = dp[i][j+1][1];
                            }
                        }
                        else {
                            if (i + 1 < m) {
                                down = dp[i+1][j][0];
                            }
                        }
                    }


                    dp[i][j][dir] = (right + down) % mod;
                }
            }
        }

        return dp[0][0][0]; 
    }
};