class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid[0].size(), m = grid.size();
        int row = 0, col = n-1, count = 0;
        while (row < m && col >=0) {
            while (col >= 0 && grid[row][col] < 0) {
                count += m - row;
                col--;
            }
            row++;
        }
        return count;
    }
};