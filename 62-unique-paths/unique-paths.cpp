class Solution {
private:
    int backtrack(int i, int j, vector<vector<int>> &dp) {
        if (i == 0 && j == 0) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        int paths = 0;
        if (i-1 >= 0) {
            paths += backtrack(i-1, j, dp);
        }
        if (j-1 >= 0) {
            paths += backtrack(i, j-1, dp);
        }

        return dp[i][j] = paths;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return backtrack(m-1, n-1, dp);
    }
};