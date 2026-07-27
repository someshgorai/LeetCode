class Solution {
public:
    using ll = long long;
    using T = tuple<ll, int, int, bool>;

    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        priority_queue<T, vector<T>, greater<T>> pq;

        vector<vector<vector<ll>>> dist(
            m, vector<vector<ll>>(n, vector<ll>(2, 1e18)));

        int drow[2][2] = {{0, 1}, {0, -1}};
        int dcol[2][2] = {{-1, 0}, {1, 0}};

        dist[0][0][0] = 1;
        pq.push({1, 0, 0, 0});

        while (!pq.empty()) {
            auto [cur, x, y, p] = pq.top();
            pq.pop();

            if (cur != dist[x][y][p])
                continue;

            if (x == m - 1 && y == n - 1)
                return cur;

            if (cur + penalty[x][y] < dist[x][y][!p]) {
                dist[x][y][!p] = cur + penalty[x][y];
                pq.push({dist[x][y][!p], x, y, !p});
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    int r = x + drow[i][j];
                    int c = y + dcol[i][j];

                    if (r < 0 || c < 0 || r >= m || c >= n)
                        continue;

                    ll nxt = cur + 1LL * (r + 1) * (c + 1);

                    bool legal = (p == 0 ? (i != j) : (i == j));
                    if (!legal)
                        nxt += penalty[x][y];

                    if (nxt < dist[r][c][!p]) {
                        dist[r][c][!p] = nxt;
                        pq.push({nxt, r, c, !p});
                    }
                }
            }
        }

        return -1;
    }
};