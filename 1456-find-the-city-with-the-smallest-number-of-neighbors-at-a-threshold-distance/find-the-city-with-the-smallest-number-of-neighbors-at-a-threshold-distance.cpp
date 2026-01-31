class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));

        // Distance to itself = 0
        for(int i = 0; i < n; i++) dist[i][i] = 0;

        // Fill edges
        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Floyd–Warshall
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        int answer = -1;
        int minReachable = INF;

        // Count reachable cities
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && dist[i][j] <= distanceThreshold)
                    cnt++;
            }

            // smallest count, tie → greatest index
            if(cnt <= minReachable) {
                minReachable = cnt;
                answer = i;
            }
        }

        return answer;
    }
};
