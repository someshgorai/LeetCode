class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int> (m, -1));

        for (int i = 0; i <= m-2; i++) {
            dp[i][i+1] = 0;
            dp[i+1][i] = 0;
        }

        for (int l = m-1; l >= 0; l--) {
            for (int r = l+2; r <= m-1; r++) {
                int minCost = 1e9;
                for (int i = l+1; i < r; i++) {
                    minCost = min(
                        minCost, 
                        cuts[r] - cuts[l] + 
                        dp[l][i] +
                        dp[i][r]
                    );
                }

                dp[l][r] = minCost;
            }
        }
        return dp[0][m-1];
    }
};