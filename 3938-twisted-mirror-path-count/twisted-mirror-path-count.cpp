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
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, -1)));
        return getValidPathsCount(0, 0, m, n, 0, grid, dp); 
    }
};