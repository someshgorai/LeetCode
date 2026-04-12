class Solution {
private:
    int dp[301][7][7][7][7];
    int solve(string &word, int n, int i, int x1, int y1, int x2, int y2) {
        if (i >= n) return 0;

        if (dp[i+1][x1+1][y1+1][x2+1][y2+1] != -1) return dp[i+1][x1+1][y1+1][x2+1][y2+1];

        char c = word[i];
        int x = (c - 'A') % 6;
        int y = (c - 'A') / 6;

        int moveFinger1 = solve(word, n, i + 1, x, y, x2, y2);
        int moveFinger2 = solve(word, n, i + 1, x1, y1, x, y);

        if (x1 != -1 && y1 != -1) moveFinger1 += abs(x1 - x) + abs(y1 - y);
        if (x2 != -1 && y2 != -1) moveFinger2 += abs(x2 - x) + abs(y2 - y);

        return dp[i+1][x1+1][y1+1][x2+1][y2+1] = min(moveFinger1, moveFinger2);
    }
public:
    int minimumDistance(string word) {
        int n = word.size();
        memset(dp, -1, sizeof(dp));
        return solve(word, n, 0, -1, -1, -1, -1);
    }
};