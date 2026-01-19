class Solution {
private:
    bool dfsCheck(int node, vector<vector<int>> &graph, vector<bool> &path, vector<bool> &vis, vector<bool> & check) {  
        vis[node] = true;
        path[node] = true;
        for (int i:graph[node]) {
            if (!vis[i]) {
                if (dfsCheck(i, graph, path, vis, check)) return true;
            }
            else if (path[i]) return true;
        }
        check[node] = true;
        path[node] = false;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false), path(n, false), check(n, false);
        vector<int> safeNodes;
        
        for (int i=0; i<n; i++) {
            if (!vis[i]) dfsCheck(i, graph, path, vis, check);
        }
        for (int i=0; i<n; i++) {
            if (check[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};