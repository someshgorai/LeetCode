# include <bits/stdc++.h>
class Solution {
private:
    bool isPathPossible(vector<vector<int>>& grid, vector<pair<int, int>> &st, int sf, int i, int j, int n,
        vector<vector<bool>> &vis) {
        if (i == n-1 && j == n-1) return true;

        vis[i][j] = true;

        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        for (int k = 0; k < 4; k++) {
            int row = i + drow[k];
            int col = j + dcol[k];

            if (row >= 0 && row < n && col >= 0 && col < n && !vis[row][col]) {
                int cellSF = INT_MAX;
                for (auto &thief : st) {
                    cellSF = min(cellSF, abs(row - thief.first) + abs(col - thief.second));
                }
                if (cellSF >= sf && isPathPossible(grid, st, sf, row, col, n, vis)) {
                    return true;
                }
            }
        }

        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // edge cases
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;

        vector<pair<int, int>> st;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) st.push_back({i, j});
            }
        }

        int maxSF = 0;

        int startSF = INT_MAX;

        for (auto &thief : st) {
            startSF = min(startSF,
                        abs(thief.first) +
                        abs(thief.second));
        }

        for (int i = 1; i <= 2*(n-1); i++) {
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            if (startSF >= i && isPathPossible(grid, st, i, 0 , 0, n, vis)) maxSF = max(maxSF, i);
        }

        return maxSF;
    }
};