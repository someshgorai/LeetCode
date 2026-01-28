class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adjlist(n);
        for (auto &edge : edges) {
            adjlist[edge[0]].push_back({edge[1], edge[2]});
            adjlist[edge[1]].push_back({edge[0], edge[2] * 2});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.emplace(0, 0);
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        while (!pq.empty()) {
            int travelled = pq.top().first;
            int node = pq.top().second;
            if (node == n-1) return travelled;
            pq.pop();
            if (travelled > dist[node]) continue;
            for (auto &i : adjlist[node]) {
                int v = i.first;
                int d = i.second;
                if (travelled + d < dist[v]) {
                    dist[v] = travelled + d;
                    pq.emplace(dist[v], v);
                }
            }
        }

        if (dist[n-1] == INT_MAX) return -1;
        return dist[n-1];
    }
};