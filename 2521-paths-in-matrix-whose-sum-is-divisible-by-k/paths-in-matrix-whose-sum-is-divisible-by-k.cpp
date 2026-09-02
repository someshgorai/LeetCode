class Solution {
private:
    int backtrack(int i, int j, int sum, int m, int n, vector<vector<int>>& grid, int k,
    vector<vector<vector<int>>>& dp) {
        sum = (sum + grid[i][j]) % k;

        if (i == m-1 && j == n-1) {
            if (sum == 0) return 1;
            return 0;
        }

        if (dp[i][j][sum] != -1) return dp[i][j][sum];

        int right = 0;
        if (j + 1 < n) { 
            right = backtrack(i, j + 1, sum, m, n, grid, k, dp);
        }

        int down = 0;
        if (i + 1 < m) {
            down  = backtrack(i+1, j, sum, m, n, grid, k, dp);
        }

        return dp[i][j][sum] = (right + down) % mod;
    }
public:
    int mod = 1e9 + 7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (k, -1)));
        return backtrack(0, 0, 0, m, n, grid, k, dp);
    }
};