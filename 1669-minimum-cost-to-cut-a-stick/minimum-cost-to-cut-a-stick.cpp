class Solution {
private:
    int backtrack(int l, int r, vector<int>& cuts, vector<vector<int>> &dp) {
        if (r - l  == 1) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        int minCost = 1e9;
        for (int i = l+1; i < r; i++) {
            minCost = min(
                minCost, 
                cuts[r] - cuts[l] + 
                backtrack(l, i, cuts, dp) +
                backtrack(i, r, cuts, dp)
            );
        }

        return dp[l][r] = minCost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int> (m, -1));
        return backtrack(0, m-1, cuts, dp);
    }
};