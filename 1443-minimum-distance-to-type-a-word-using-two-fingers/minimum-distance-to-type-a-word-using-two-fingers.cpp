class Solution {
private:
    int dp[27][27];

    pair<int, int> getCoordinate(int c) {
        return {c % 6, c / 6};
    }

    int getDistance(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }
public:
    int minimumDistance(string word) {
        int n = word.size();
        memset(dp, 0, sizeof(dp));

        for (int i = n-1; i >= 0; i--) {
            for (int c1 = 0; c1 <= 26; c1++) {
                for (int c2 = 0; c2 <= 26; c2++) {
                    auto [x, y] = getCoordinate(word[i] - 'A');

                    int moveFinger1 = dp[word[i] - 'A'][c2];
                    int moveFinger2 = dp[c1][word[i] - 'A'];

                    auto [x1, y1] = getCoordinate(c1);
                    auto [x2, y2] = getCoordinate(c2);

                    if (c1 != 26) moveFinger1 += getDistance(x, y, x1, y1);
                    if (c2 != 26) moveFinger2 += getDistance(x, y, x2, y2);

                    dp[c1][c2] = min(moveFinger1, moveFinger2);
                }
            }
        }

        return dp[26][26];
    }
};