class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<bool>> vis(m, vector<bool> (n, false));
        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    vis[i][j] = true;
                    q.push({0, {i, j}});
                }
            }
        }

        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};

        vector<vector<int>> ans(m, vector<int> (n , 0));

        while (!q.empty()) {
            auto [dist, locus] = q.front();
            auto [i, j]        = locus;
            q.pop();

            ans[i][j] = dist;

            for (int k = 0; k < 4; k++) {
                int r = i + drow[k];
                int c = j + dcol[k];

                if (r < 0 || c < 0 || r >= m || c >= n) continue;
                if (!vis[r][c]) {
                    vis[r][c] = true;
                    q.push({dist + 1, {r, c}});
                }   
            }
        }

        return ans;
    }
};