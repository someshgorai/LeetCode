class Solution {
private:
    int backtrack(int idx, int n, vector<int> &stones, vector<int> &dp){
        if (idx == n-1) return stones[idx+1];

        if (dp[idx] != -1) return dp[idx];

        int take = stones[idx+1] - backtrack(idx+1, n, stones, dp);
        int notTake = backtrack(idx+1, n, stones, dp);

        return dp[idx] = max(take, notTake);
    }
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size(); 
        vector<int> prefix(n+1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i+1] = stones[i] + prefix[i];
        }

        int prev = prefix[n];
        int curr;

        for (int idx = n-2; idx >= 0; idx--) {
            int take = prefix[idx+1] - prev;
            int notTake = prev;
            curr = max(take, notTake);
            swap(curr, prev);
        }

        return curr;
    }
};