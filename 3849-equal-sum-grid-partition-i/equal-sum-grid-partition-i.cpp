class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> rowSum(m, 0), colSum(n, 0);
        long long totSum = 0;

        for (int i = 0; i < m; i++) {
            long long row = 0;
            for (int j = 0; j < n; j++) {
                row += grid[i][j];
                colSum[j] += grid[i][j];
                totSum += grid[i][j];                
            }
            rowSum[i] = row;
        }

        if (totSum & 1) return false;

        long long row = 0;
        for (int i = 0; i < m; i++) {
            row += rowSum[i]; 
            if (totSum - 2 * row == 0) return true;
        }

        long long col = 0;
        for (int j = 0; j < n; j++) {
            col += colSum[j];
            if (totSum - 2*col == 0) return true;
        }

        return false;
    }
};