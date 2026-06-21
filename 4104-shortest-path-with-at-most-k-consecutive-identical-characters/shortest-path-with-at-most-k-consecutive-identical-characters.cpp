class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<vector<int>> costs(n, vector<int> (k+1, 1e9));
        using T = tuple<long long, int, int>; // {cost, node, cons}
        priority_queue<T, vector<T>, greater<T>> pq;

        costs[0][1] = 0;
        pq.push({0, 1, 0});

        while(!pq.empty()) {
            auto [cost, cons, node] = pq.top();
            pq.pop();

            if (cost > costs[node][cons]) continue;
            if (node == n-1) return (int)cost;

            for (auto next : adj[node]) {
                int newCons;
                if (labels[node] == labels[next.first]) {
                    newCons = cons + 1;
                }
                else {
                    newCons = 1;
                }

                if (newCons > k) continue;

                long long nd = cost + next.second;
                if (nd < costs[next.first][newCons]) {
                    costs[next.first][newCons] = nd;
                    pq.push({nd, newCons, next.first});
                }
            }
        }
        return -1;
    }
};