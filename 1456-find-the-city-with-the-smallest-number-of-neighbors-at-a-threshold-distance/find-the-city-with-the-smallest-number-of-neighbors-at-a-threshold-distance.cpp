class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        auto dijkstra = [&](int src) {
            const int INF = 1e9;
            vector<int> dist(n, INF);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

            dist[src] = 0;
            pq.push({0, src});

            while(!pq.empty()) {
                auto [d, node] = pq.top();
                pq.pop();

                if(d > dist[node]) continue;

                for(auto &[nbr, w] : adj[node]) {
                    if(dist[node] + w < dist[nbr]) {
                        dist[nbr] = dist[node] + w;
                        pq.push({dist[nbr], nbr});
                    }
                }
            }

            return dist;
        };

        int answer = -1;
        int minReachable = 1e9;

        for(int i = 0; i < n; i++) {

            vector<int> dist = dijkstra(i);

            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && dist[j] <= distanceThreshold)
                    cnt++;
            }

            // smaller count, tie -> larger index
            if(cnt <= minReachable) {
                minReachable = cnt;
                answer = i;
            }
        }

        return answer;
    }
};
