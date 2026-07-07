class Solution {
private:
    int dir[3] = {-1, 0, 1};
    int backtrack(int r, int c1, int c2, int m, int n, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
        // Base Case
        if (r == m-1) {
            if (c1 == c2) return grid[r][c1];
            else return grid[r][c1] + grid[r][c2];
        }

        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int maxCherries = 0;
        for (int k = 0; k < 3; k++) {
            int y1 = c1 + dir[k];

            if (y1 < 0 || y1 >= n) continue;
            for (int l = 0; l < 3; l++) {
                int y2 = c2 + dir[l];

                if (y2 < 0 || y2 >= n) continue;

                maxCherries = max(maxCherries, backtrack(r+1, y1, y2, m, n, grid, dp));
            }
        }

        if (c1 == c2) {
            return dp[r][c1][c2] = maxCherries + grid[r][c1];
        }
        return dp[r][c1][c2] = maxCherries + grid[r][c1] + grid[r][c2];
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return backtrack(0, 0, n-1, m, n, grid, dp);
    }
};