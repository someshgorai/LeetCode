class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze[0].size(), m = maze.size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(m, vector<int> (n, 1e9));
        q.push({0, {entrance[0], entrance[1]}});
        dist[entrance[0]][entrance[1]] = 0;
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int travel = q.front().first;
            auto [x, y] = q.front().second;
            if ((x == 0 || y == 0 || x == m-1 || y == n-1) && travel > 0) return travel;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = x + drow[i];
                int c = y + dcol[i];

                if (r >= 0 && c >= 0 && r < m && c < n && maze[r][c] == '.') {
                    if (travel + 1 < dist[r][c]) {
                        q.push({travel + 1, {r, c}});
                        dist[r][c] = travel + 1;
                    }
                }
            }
        } 

        return -1;
    }
};