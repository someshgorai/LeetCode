class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> dist(n, vector<int> (n, 1e9));
        dist[0][0] = 1;
        queue<pair<int, pair<int, int>>> q;

        q.push({1, {0, 0}});
        int drow[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
        int dcol[8] = {0, +1, +1, +1, 0, -1, -1, -1};
        while (!q.empty()) {
            int travelled = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            if (travelled > dist[x][y]) continue;
            for (int i = 0; i < 8; i++) {
                int r = x + drow[i];
                int c = y + dcol[i];
                if (r < n && c < n && r >= 0 && c >= 0 && grid[r][c] == 0) {
                    if (travelled + 1 < dist[r][c]) {
                        q.push({travelled + 1, {r, c}});
                        dist[r][c] = travelled + 1;
                    }
                }
            }
        }
        if (dist[n-1][n-1] >= 1e9) return -1;
        return dist[n-1][n-1];
    }
};