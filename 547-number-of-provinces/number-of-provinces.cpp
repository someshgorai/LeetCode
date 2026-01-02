class Solution {
private:
    void bfs(int start, vector<vector<int>> &isConnected, vector<int> &vis, int n) {
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto i=0; i<n; i++) {
                if (!vis[i] && isConnected[node][i]) {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (!vis[i]) {
                bfs(i, isConnected, vis, n);
                cnt++;
            }
        }
        return cnt;
    }
};