class Solution {
private:
    bool dfs(int node, vector<bool>& vis, vector<bool>& pathVis,
             vector<vector<int>>& adj, vector<int>& order) {

        vis[node] = true;
        pathVis[node] = true;

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                if (!dfs(nei, vis, pathVis, adj, order))
                    return false;
            }
            else if (pathVis[nei]) {
                return false; // cycle
            }
        }

        pathVis[node] = false;
        order.push_back(node);
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {

        vector<vector<int>> adj(numCourses);
        for (auto& p : prereq) {
            adj[p[1]].push_back(p[0]); // b -> a
        }

        vector<bool> vis(numCourses, false), pathVis(numCourses, false);
        vector<int> order;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (!dfs(i, vis, pathVis, adj, order))
                    return {};
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }
};
