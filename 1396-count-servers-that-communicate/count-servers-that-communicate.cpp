class Solution {
private:    
    int getCommunicateServerCount(int i, int j, int m, int n, vector<vector<bool>>& vis, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        int count = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            count++;

            for (int k = 0; k < n; k++) {
                if (!vis[x][k] && grid[x][k] == 1) {
                    q.push({x, k});
                    vis[x][k] = true;
                }
            }

            for (int l = 0; l < m; l++) {
                if (!vis[l][y] && grid[l][y] == 1) {
                    q.push({l, y});
                    vis[l][y] = true;
                }
            }
        }

        return count == 1 ? 0 : count;
    }
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));

        int serverCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    serverCount += getCommunicateServerCount(i, j, m, n, vis, grid);
                }
            }
        }

        return serverCount;
    }
};