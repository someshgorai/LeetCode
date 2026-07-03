class Solution {
private:
    bool isPossible(int n, long long k, int minScore, vector<vector<pair<int, int>>> &adj) {
        vector<long long> dist(n, LLONG_MAX);
        typedef tuple<long long, int> T;

        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[node]) continue;

            if (node == n-1) return true;

            for (auto [neighbor, wt] : adj[node]) {
                if (wt < minScore) continue;

                if (wt + cost < dist[neighbor] && wt + cost <= k) {
                    dist[neighbor] = wt + cost;
                    pq.push({wt+cost, neighbor});
                }
            }
        }

        return false;
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        int low = 1e9, high = 0;

        vector<vector<pair<int, int>>> adj(n);
        for (auto edge : edges) {
            if (!online[edge[0]] || !online[edge[1]]) continue;

            adj[edge[0]].push_back({edge[1], edge[2]});
            low = min(low, edge[2]);
            high = max(high, edge[2]);
        }


        bool noWays = true;
        while (low <= high) {
            int mid = (high - low)/2 + low;

            if (isPossible(n, k, mid, adj)) {
                noWays = false;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        if (noWays) return -1;
        return high;
    }
};