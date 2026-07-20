class Solution {
public:
    void reverse(int i, int j, vector<vector<int>> &grid) {
        int n = grid[0].size();
        while (i < j) {
            swap(grid[i/n][i%n], grid[j/n][j%n]);
            i++;
            j--;
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int l = m * n;
        k  = k % l;

        reverse(0, l-1, grid);
        reverse(0, k-1, grid);
        reverse(k, l-1, grid);

        return grid;
    }
};