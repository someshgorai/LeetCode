class Solution {
private:   
    vector<bool> getSuspicious(int start,  vector<vector<int>> &adj, int n) {
        queue<int> q;
        vector<bool> vis(n);
        q.push(start);
        vis[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    q.push(neighbor);
                    vis[neighbor] = true;
                }
            }
        }

        return vis;
    }
    bool isInvokeSus(int start, vector<bool> &vis, vector<bool> &susMethods, vector<vector<int>> &adj, int n) {
        queue<int> q;
        q.push(start);
        vis[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto neighbor : adj[node]) {
                if (susMethods[neighbor]) return true;
                if (!vis[neighbor]) {
                    q.push(neighbor);
                    vis[neighbor] = true;
                }
            }
        }

        return false;
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> susMethods, vis(n);
        susMethods = getSuspicious(k, adj, n);

        bool invokeSus = false;
        for (int i = 0; i < n; i++) {
            if (susMethods[i]) continue;
            if (vis[i])    continue;
            invokeSus = isInvokeSus(i, vis, susMethods, adj, n);
            if (invokeSus) break;
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!invokeSus) {
                if (!susMethods[i]) res.push_back(i);
            }
            else {
                res.push_back(i);
            }
        }

        return res;
    }
};