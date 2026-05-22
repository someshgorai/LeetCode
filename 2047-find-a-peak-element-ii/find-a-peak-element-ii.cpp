class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({mat[0][0], {0 , 0}});
        vis[0][0] = true;

        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [val, pos] = pq.top();
            auto [i, j] = pos;
            vis[i][j] = true;
            pq.pop();
            bool greater = true;

            for (int k = 0; k < 4; k++) {
                int row = i + drow[k];
                int col = j + dcol[k];

                if (row >= 0 && row < m && col >= 0 && col < n) {
                    if (mat[row][col] > val) greater = false;
                    if (!vis[row][col]) {
                        vis[row][col] = true;
                        pq.push({mat[row][col], {row, col}});
                    }
                }
            }
            if (greater) return {i, j};
        }

        return {-1, -1};
    }
};