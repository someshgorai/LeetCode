class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        set<pair<int, pair<int, int>>> st;
        dist[0][0] = 1;
        st.insert({1, {0, 0}}); 

        int drow[] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while (!st.empty()) {
            auto it = *st.begin();
            st.erase(it);
            auto [x, y] = it.second;
            int travel = it.first;

            for (int i = 0; i < 8; i++) {
                int r = x + drow[i];
                int c = y + dcol[i];

                if (r >= 0 && c >= 0 && r < n && c < n && grid[r][c] == 0) {
                    if (travel + 1 < dist[r][c]) {
                        if (dist[r][c] != 1e9) {
                            st.erase({dist[r][c], {r, c}});   
                        }
                        st.insert({travel + 1, {r, c}});
                        dist[r][c] = travel + 1;
                        if (r == n-1 && c == n-1) return dist[r][c];
                    }
                }
            }
        }

        return dist[n-1][n-1] == 1e9 ? -1 : dist[n-1][n-1];
    }
};