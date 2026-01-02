class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis, int n) {
        vis[node] = 1;
        for (int j=0; j<n; j++) {
            if (!vis[j] && isConnected[node][j]) {
                dfs(j, isConnected, vis, n);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;
        vector<int> vis(n, 0);
        for (int i=0; i<n; i++) {
            if (!vis[i]) {
                dfs(i, isConnected, vis, n);
                cnt++;
            }
        }
        return cnt;
    }
};