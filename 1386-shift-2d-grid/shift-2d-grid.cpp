class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int l = m * n;
        k = k % l;

        vector<vector<int>> temp(m, vector<int> (n));

        for (int i = 0; i < l; i++) {
            int x = i / n;
            int y = i % n;
            int nx = ((i+k)%l) / n;
            int ny = ((i+k)%l) % n;
            temp[nx][ny] = grid[x][y];
        }
        return temp;
    }
};