class Solution {
private:
    int dp[301][27][27];

    pair<int, int> getCoordinate(int c) {
        return {c % 6, c / 6};
    }

    int getDistance(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    int solve(string &word, int n, int i, int c1, int c2) {
        if (i >= n) return 0;

        if (dp[i][c1][c2] != -1) return dp[i][c1][c2];

        auto [x, y] = getCoordinate(word[i] - 'A');

        int moveFinger1 = solve(word, n, i + 1, word[i] - 'A', c2);
        int moveFinger2 = solve(word, n, i + 1, c1, word[i] - 'A');

        auto [x1, y1] = getCoordinate(c1);
        auto [x2, y2] = getCoordinate(c2);

        if (c1 != 26) moveFinger1 += getDistance(x, y, x1, y1);
        if (c2 != 26) moveFinger2 += getDistance(x, y, x2, y2);

        return dp[i][c1][c2] = min(moveFinger1, moveFinger2);
    }
public:
    int minimumDistance(string word) {
        int n = word.size();
        memset(dp, -1, sizeof(dp));
        return solve(word, n, 0, 26, 26);
    }
};