class Solution {
private:
    int backtrack(int idx, int m, int person, int n, vector<int> &piles, vector<vector<vector<int>>> &dp) {
        if (idx >= n) return 0;

        if (dp[person][m][idx] != -1) return dp[person][m][idx];

        int sum = 0;
        int limit = 2 * m;
        int score;
        if (person == 1) score = 0;
        else score = INT_MAX;

        for (int x = 1; x <= limit; x++) {
            if (idx + x - 1 >= n) break;
            sum += piles[idx + x - 1];
            if (person == 1) {
                score = max(score, sum + backtrack(idx + x, max(m, x), 0, n, piles, dp));
            }
            else {
                score = min(score, backtrack(idx + x, max(m, x), 1, n, piles, dp));
            }
        } 

        return dp[person][m][idx] = score;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>> (200, vector<int> (100, -1)));
        return backtrack(0, 1, 1, n, piles, dp);
    }
};