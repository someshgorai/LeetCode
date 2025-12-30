class Solution {
private:
    bool isMagicSquare(vector<vector<int>>& g, int r, int c) {
        vector<int> seen(10, 0);

        // Check 1–9 uniqueness
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int v = g[i][j];
                if (v < 1 || v > 9 || seen[v]) return false;
                seen[v] = 1;
            }
        }

        int sum = g[r][c] + g[r][c+1] + g[r][c+2];

        // Rows
        for (int i = 0; i < 3; i++) {
            if (g[r+i][c] + g[r+i][c+1] + g[r+i][c+2] != sum)
                return false;
        }

        // Columns
        for (int j = 0; j < 3; j++) {
            if (g[r][c+j] + g[r+1][c+j] + g[r+2][c+j] != sum)
                return false;
        }

        // Diagonals
        if (g[r][c] + g[r+1][c+1] + g[r+2][c+2] != sum)
            return false;
        if (g[r][c+2] + g[r+1][c+1] + g[r+2][c] != sum)
            return false;

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;

        for (int i = 0; i <= m - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                if (isMagicSquare(grid, i, j)) cnt++;
            }
        }
        return cnt;
    }
};
