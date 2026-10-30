class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bitset<1024> up = 0, left = 0, comb;

                if (i - 1 >= 0) up = dp[i - 1][j];
                if (j - 1 >= 0) left = dp[i][j - 1];

                comb = up | left;

                for (int k = 0; k < 1024; k++) {
                    if (comb[k] == true) {
                        dp[i][j][grid[i][j] ^ k] = true;
                    }
                }
            }
        }

        for (int k = 0; k < 1024; k++) {
            if (dp[m-1][n-1][k] == true) {
               return k;
            }
        }

        return -1;
    }
};