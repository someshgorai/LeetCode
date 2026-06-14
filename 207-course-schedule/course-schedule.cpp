class Solution {
private:
    void toposort(int node, vector<vector<int>> &dirGraph, vector<bool> &vis, int &count) {
        queue<int> q;
        q.push(node);
        vis[node] = true;

        while (!q.empty()) {
            int node = q.front();
            count++;
            q.pop();

            for (int neigh : dirGraph[node]) {
                if (!vis[neigh]) {
                    q.push(neigh);
                    vis[neigh] = true;
                }

            }
        }
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> dirGraph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto pre : prerequisites) {
            dirGraph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        
        int count = 0;
        vector<bool> vis(numCourses, false);
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                vis[i] = true;
            }
        }

        while (!q.empty()) {
            int node = q.front();
            count++;
            q.pop();

            for (int neigh : dirGraph[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0){
                    q.push(neigh);
                    vis[neigh];
                }
            }
        }

        if (count == numCourses) return true;
        return false;
    }
};