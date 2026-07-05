class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(2, 0)));

        for (int i = n - 1; i >= 0; i--) {
            fill(dp[0].begin(), dp[0].end(), vector<int>{0, 0});

            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 'X') continue;

                if (i == n - 1 && j == n - 1) {
                    dp[0][j] = {0, 1};
                    continue;
                }

                int best = -1;
                int ways = 0;

                // down
                if (i + 1 < n) {
                    auto &cur = dp[1][j];
                    if (cur[1]) {
                        if (cur[0] > best) {
                            best = cur[0];
                            ways = cur[1];
                        } else if (cur[0] == best) {
                            ways = (ways + cur[1]) % mod;
                        }
                    }
                }

                // right
                if (j + 1 < n) {
                    auto &cur = dp[0][j + 1];
                    if (cur[1]) {
                        if (cur[0] > best) {
                            best = cur[0];
                            ways = cur[1];
                        } else if (cur[0] == best) {
                            ways = (ways + cur[1]) % mod;
                        }
                    }
                }

                // diagonal
                if (i + 1 < n && j + 1 < n) {
                    auto &cur = dp[1][j + 1];
                    if (cur[1]) {
                        if (cur[0] > best) {
                            best = cur[0];
                            ways = cur[1];
                        } else if (cur[0] == best) {
                            ways = (ways + cur[1]) % mod;
                        }
                    }
                }

                if (ways == 0) continue;

                int score = best;
                if (board[i][j] != 'S' && board[i][j] != 'E')
                    score += board[i][j] - '0';

                dp[0][j] = {score, ways};
            }

            swap(dp[0], dp[1]);
        }

        return dp[1][0];
    }
};