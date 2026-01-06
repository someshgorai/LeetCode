class Solution {
private:
    int drow[4] = {-1, 0, +1, 0};
    int dcol[4] = {0, +1, 0, -1};
    void dfs(int sr, int sc, vector<vector<int>> &ans, int iniColor, int color, int m, int n) {
        if (sr < 0 || sc < 0 || sc > n || sr > m) return;
        for (int i=0; i<4; i++) {
            int row = sr + drow[i];
            int col = sc + dcol[i];
            if (row >= 0 && col >= 0 && row < m && col < n && ans[row][col] == iniColor) {
                ans[row][col] = color;
                dfs(row, col, ans, iniColor, color, m, n);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        if (iniColor == color) return image; 
        vector<vector<int>> ans = image;
        int m = image.size(), n = image[0].size();
        ans[sr][sc] = color;
        dfs(sr, sc, ans, iniColor, color, m, n);
        return ans;
    }
};