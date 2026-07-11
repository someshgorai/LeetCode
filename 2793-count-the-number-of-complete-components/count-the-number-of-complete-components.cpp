class Solution {
private:
    int dfs(int node, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[node] = true;

        int count = 0;
        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                count += dfs(neighbor, adj, vis);
            }
        }

        return count+1;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);

        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int start = 0; start < n; start++) {
            if (!vis[start]) {
                vector<bool> visTemp(n, false);
                int nodes = dfs(start, adj, visTemp);

                bool isComplete = true;
                for (int i= 0; i < n; i++) {
                    if (visTemp[i]){
                        vis[i] = true;
                        if (nodes != adj[i].size() + 1) {
                            isComplete = false;
                        }
                    }
                }
                if (isComplete) count++;
            }
        }

        return count;
    }
};