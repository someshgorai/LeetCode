class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix[0].size(), m = matrix.size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int y = 0; y < n; y++) {
                matrix[i][y] = 0;
            }
            for (int x = 0; x < m; x++) {
                matrix[x][j] = 0;
            }
        }
        
    }
};