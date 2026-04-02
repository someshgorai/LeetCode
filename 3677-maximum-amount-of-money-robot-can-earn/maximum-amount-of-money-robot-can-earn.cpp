class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        const int NEG = INT_MIN / 2;

        vector<vector<int>> next(n, vector<int>(3, NEG));

        // Base case (last row initialization)
        for (int k = 0; k <= 2; k++) {
            if (coins[m-1][n-1] < 0 && k > 0)
                next[n-1][k] = 0;
            else
                next[n-1][k] = coins[m-1][n-1];
        }

        // Fill last row (right → left)
        for (int j = n - 2; j >= 0; j--) {
            for (int k = 0; k <= 2; k++) {
                int val = coins[m-1][j];

                int take = val + next[j+1][k];

                int skip = NEG;
                if (val < 0 && k > 0) {
                    skip = next[j+1][k-1];
                }

                next[j][k] = max(take, skip);
            }
        }

        // Process remaining rows
        for (int i = m - 2; i >= 0; i--) {
            vector<vector<int>> curr(n, vector<int>(3, NEG));

            for (int j = n - 1; j >= 0; j--) {
                for (int k = 0; k <= 2; k++) {
                    int val = coins[i][j];

                    int right = (j + 1 < n) ? curr[j+1][k] : NEG;
                    int down  = next[j][k];

                    int bestNext = max(right, down);

                    // Take
                    int take = val + bestNext;

                    // Skip
                    int skip = NEG;
                    if (val < 0 && k > 0) {
                        int r = (j + 1 < n) ? curr[j+1][k-1] : NEG;
                        int d = next[j][k-1];
                        skip = max(r, d);
                    }

                    curr[j][k] = max(take, skip);
                }
            }

            next = curr;
        }

        return next[0][2];
    }
};