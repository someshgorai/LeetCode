class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {-1, -1}, {0, -1}};
    int mod = 1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

        dp[0][0] = {0, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                int maxSum = 0, paths = 0;
                for (int d = 0; d < 3; d++) {
                    int x = i + dir[d].first;
                    int y = j + dir[d].second;

                    if (x >= 0 && x < n && y >= 0 && y < n && board[x][y] != 'X') {
                        auto res = dp[x][y];
                        if (maxSum < res[0]) {
                            maxSum = res[0];
                            paths = res[1];
                        }
                        else if (res[0] == maxSum){
                            paths = (paths + res[1]) % mod;
                        }
                    }
                }
                if (paths == 0) dp[i][j] = {0, 0};
                else if (board[i][j] == 'S') dp[i][j] = {maxSum, paths};
                else dp[i][j] = {(board[i][j] - '0') + maxSum, paths};
            }
        }

        return dp[n-1][n-1];
    }
};