class Solution {
private:

    bool isPossible(vector<vector<int>>& dist, int sf, int n) {

        if (dist[0][0] < sf)
            return false;

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        q.push({0,0});
        vis[0][0] = true;

        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};

        while (!q.empty()) {

            auto [r,c] = q.front();
            q.pop();

            if (r == n-1 && c == n-1)
                return true;

            for (int k = 0; k < 4; k++) {

                int nr = r + drow[k];
                int nc = c + dcol[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc] & dist[nr][nc] >= sf) {
                    vis[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }

        return false;
    }

public:

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        queue<pair<int,int>> q;

        // multi-source BFS from thieves
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};

        while (!q.empty()) {

            auto [r,c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nr = r + drow[k];
                int nc = c + dcol[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == INT_MAX) {

                    dist[nr][nc] =
                        dist[r][c] + 1;

                    q.push({nr,nc});
                }
            }
        }

        int low = 0;
        int high = 2 * (n - 1);

        int ans = 0;

        while (low <= high) {

            int mid = low + (high - low)/2;

            if (isPossible(dist, mid, n)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};