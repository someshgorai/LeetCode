class Solution {
private:  
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    long long getIslandValue(int i, int j, int m, int n, vector<vector<bool>>& vis, vector<vector<int>>& grid) {
        vis[i][j] = true;

        long long value = 0;
        for (int k = 0; k < 4; k++) {
            int r = i + drow[k];
            int c = j + dcol[k];

            if (r >= 0 && r < m && c >= 0 && c < n && !vis[r][c] && grid[r][c] != 0) {
                value += getIslandValue(r, c, m, n, vis, grid);
            }
        }

        return value + grid[i][j];
    }   
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] != 0) {
                    long long totValue = getIslandValue(i, j, m, n, vis, grid) ;
                    cout << totValue << ' ';
                    if (totValue % k == 0) cnt++;
                }
            }
        }

        return cnt;
    }
};