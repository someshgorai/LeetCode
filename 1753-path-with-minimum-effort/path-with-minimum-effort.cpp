class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> diff(m, vector<int> (n, 1e9));
        pq.push({0, {0, 0}});
        diff[0][0] = 0;
        int drow[4] = {-1, 0, +1, 0};
        int dcol[4] = {0, +1, 0, -1};
        
        while (!pq.empty()) {
            int effort = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if (effort > diff[x][y]) continue;
            for (int i = 0; i < 4; i++) {
                int r = x + drow[i];
                int c = y + dcol[i];
                if (r < m && r >= 0 && c < n && c >= 0) {
                    int newEffort = max(effort, abs(heights[x][y] - heights[r][c]));
                    if (newEffort < diff[r][c]) {
                        diff[r][c] = newEffort;
                        pq.push({diff[r][c], {r, c}});
                    }
                }
            }
        } 
        return diff[m-1][n-1];
    }
};