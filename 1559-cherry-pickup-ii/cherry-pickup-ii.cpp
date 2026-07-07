class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
        int dir[3] = {-1, 0, 1};

        for (int c1 = 0; c1 < n; c1++) {
            for (int c2 = 0; c2 < n; c2++) {
                if (c1 == c2) dp[m-1][c1][c2] = grid[m-1][c1];
                else dp[m-1][c1][c2] = grid[m-1][c1] + grid[m-1][c2];
            }
        }

        for (int r = m-2; r >= 0; r--) {
            for (int c1 = n-1; c1 >= 0; c1--) {
                for (int c2 = n-1; c2 >= 0; c2--) {
                    int maxCherries = 0;
                    for (int k = 0; k < 3; k++) {
                        int y1 = c1 + dir[k];

                        if (y1 < 0 || y1 >= n) continue;
                        for (int l = 0; l < 3; l++) {
                            int y2 = c2 + dir[l];

                            if (y2 < 0 || y2 >= n) continue;

                            maxCherries = max(maxCherries, dp[r+1][y1][y2]);
                        }
                    }

                    if (c1 == c2) dp[r][c1][c2] = maxCherries + grid[r][c1];
                    else dp[r][c1][c2] = maxCherries + grid[r][c1] + grid[r][c2];
                }
            }
        }

        return dp[0][0][n-1];
    }
};