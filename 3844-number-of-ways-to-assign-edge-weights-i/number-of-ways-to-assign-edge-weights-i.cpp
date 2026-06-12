class Solution {
private:
    int mod = 1e9+7;
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
        int totalWays = 1;
        cout << maxDepth;
        for (int i = 0; i < maxDepth-1; i++) {
            totalWays = (totalWays << 1)%mod; 
        }
        return totalWays;
    }
};