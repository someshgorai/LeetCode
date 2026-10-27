class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string line = "";
        for (int i = 0; i < n; i++) {
            line += '.';
        }

        vector<string> grid(m, line);
        
        if (m > 1 && n > 1) {
            for (int i = 0; i < n-1; i++) {
                grid[1][i] = '#';
            }

            for (int i = 1; i < m; i++) {
                grid[i][n-2] = '#';
            }
        }
        
        return grid;
    }
};