class Solution {
    typedef vector<int> V;
private:    
    int backtrack(int r, int c1, int c2, int m, int n, vector<vector<int>>& grid, vector<vector<V>>& dp) {
        if (r == m) {
            return 0;
        }

        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int maxScore = 0;
        for (int i = -1; i < 2; i++) {
            int next_c1 = c1 + i;
            if (next_c1 < 0 || next_c1 >= n) continue;
            for (int j = -1; j < 2; j++) {
                int next_c2 = c2 + j;
                if (next_c2 < 0 || next_c2 >= n) continue;
                if (c1 == c2) maxScore = max(
                    maxScore, 
                    grid[r][c1] + backtrack(r + 1, next_c1, next_c2, m, n, grid, dp)
                );
                else maxScore = max(
                    maxScore, 
                    grid[r][c1] + grid[r][c2] + backtrack(r + 1, next_c1, next_c2, m, n, grid, dp)
                );
            }
        }

        return dp[r][c1][c2] = maxScore;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<V>> dp(m, vector<V>(n, V(n, -1)));
        return backtrack(0, 0, n - 1, m, n, grid, dp);
    }
};