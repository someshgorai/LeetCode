class Solution {
private:
    int mod = 1e9+7;
    long long power(int base, int expo) {
        if (expo == 0) return 1;
        long long half = power(base, expo/2);
        long res = (half * half)%mod;
        if (expo & 1) res = (res * base)%mod;
        return res;
    }
    int getMaxDepth(int node, vector<int> adj[], int parent) {
        int maxDepth = 0;

        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                maxDepth = max(maxDepth, getMaxDepth(neighbor, adj, node) + 1);
            }
        }

        return maxDepth;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> adj[n+1];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        int maxDepth = getMaxDepth(1, adj, -1);
        int totalWays = (int) power(2, maxDepth-1);
        return totalWays;
    }
};