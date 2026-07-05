class Solution {
private:
    vector<pair<int, int>> dir = {{-1, 0}, {-1, -1}, {0, -1}};
    int mod = 1e9+7;
    vector<int> backtrack(int i, int j, int n, vector<string> &board, vector<vector<vector<int>>> &dp) {
        if (board[i][j] == 'E') return {0, 1};

        if (dp[i][j][1] != -1) return dp[i][j];

        int maxSum = 0, paths = 0;
        for (int d = 0; d < 3; d++) {
            int x = i + dir[d].first;
            int y = j + dir[d].second;

            if (x >= 0 && x < n && y >= 0 && y < n && board[x][y] != 'X') {
                auto res = backtrack(x, y, n, board, dp);
                if (maxSum < res[0]) {
                    maxSum = res[0];
                    paths = res[1];
                }
                else if (res[0] == maxSum){
                    paths = (paths + res[1]) % mod;
                }
            }
        }
        if (paths == 0) return dp[i][j] = {0, 0};
        if (board[i][j] == 'S') return dp[i][j] = {maxSum, paths};
        return dp[i][j] = {(board[i][j] - '0') + maxSum, paths};
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return backtrack(n-1, n-1, n, board, dp);
    }
};