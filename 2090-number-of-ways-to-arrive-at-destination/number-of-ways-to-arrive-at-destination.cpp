class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<vector<pair<int, int>>> adjlist(n);
        for (auto &road : roads) {
            adjlist[road[0]].push_back({road[1], road[2]});
            adjlist[road[1]].push_back({road[0], road[2]});
        }
        vector<long long> time(n, 1e18);
        time[0] = 0;
        priority_queue< 
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>> > pq;

        pq.emplace(0, 0);
        vector<int> ways(n, 0);
        ways[0] = 1;
        while (!pq.empty()) {
            long long spent = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (spent > time[node]) continue;
            if (node == n-1) break;
            for (auto &[next, wt] : adjlist[node]) {
                long long newDist = spent + wt;
                if (newDist < time[next]) {
                    ways[next] = ways[node]; 
                    time[next] = spent + wt;
                    pq.emplace(time[next], next);
                }
                else if (newDist == time[next]) {
                    ways[next] = (ways[next] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1];
    }
};