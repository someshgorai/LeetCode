class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int, pair<int, int>>> q;
        dist[0][0] = 1;
        q.push({1, {0, 0}}); 

        int drow[] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            auto [x, y] = it.second;
            int travel = it.first;
            if (x == n-1 && y == n-1) return dist[x][y];

            for (int i = 0; i < 8; i++) {
                int r = x + drow[i];
                int c = y + dcol[i];

                if (r >= 0 && c >= 0 && r < n && c < n && grid[r][c] == 0) {
                    if (travel + 1 < dist[r][c]) {
                        q.push({travel + 1, {r, c}});
                        dist[r][c] = travel + 1;
                        
                    }
                }
            }
        }

        return dist[n-1][n-1] == 1e9 ? -1 : dist[n-1][n-1];
    }
};