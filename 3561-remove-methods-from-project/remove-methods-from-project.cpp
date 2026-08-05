class Solution {
private:   
    vector<bool> getSuspicious(int start,  vector<vector<int>> &adj, int n, vector<int> &indegree) {
        queue<int> q;
        vector<bool> vis(n);
        q.push(start);
        vis[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;
                if (!vis[neighbor]) {
                    q.push(neighbor);
                    vis[neighbor] = true; 
                }
            }
        }

        return vis;
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (auto edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        vector<bool> susNodes = getSuspicious(k, adj, n, indegree);

        bool isPresent = true;
        for (int i = 0; i < n; i++) {
            if (susNodes[i] == true && indegree[i] > 0) {
                isPresent = false;
                break;
            }
        }

        vector<int> res;
        if (isPresent) {
            for (int i = 0; i < n; i++) {
                if (!susNodes[i]) res.push_back(i);
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                res.push_back(i);
            }
        }

        return res;
    }
};