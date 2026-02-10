class Solution {
private:
    int timer = 0;
    void dfs(int node, int parent, vector<vector<int>> &bridges, vector<bool> &vis, vector<int> &time, vector<int> &low, vector<vector<int>> &adjlist) {
        vis[node] = true;
        time[node] = low[node] = timer;
        timer++;
        for (int &next : adjlist[node]) {
            if (next == parent) continue;
            if (!vis[next]) {
                dfs(next, node, bridges, vis, time, low, adjlist);
                low[node] = min(low[next], low[node]);
                if (low[next] > time[node]) {
                    bridges.push_back({next, node});
                }
            }
            else {
                low[node] = min(low[next], low[node]); 
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjlist(n), bridges;
        for (auto &edge : connections) {
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }
        vector<int> time(n), low(n);
        vector<bool> vis(n, false);
        dfs(0, -1, bridges, vis, time, low, adjlist);
        return bridges;
    }
};