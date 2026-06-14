class Solution {
private:
    bool isCyclic(int node,
                  vector<vector<int>>& graph,
                  vector<bool>& vis,
                  vector<bool>& pathVis) {

        vis[node] = true;
        pathVis[node] = true;

        for (int neigh : graph[node]) {
            if (!vis[neigh]) {
                if (isCyclic(neigh, graph, vis, pathVis))
                    return true;
            }
            else if (pathVis[neigh]) {
                return true; // back edge found
            }
        }

        pathVis[node] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for (auto &pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (isCyclic(i, graph, vis, pathVis))
                    return false;
            }
        }

        return true;
    }
};