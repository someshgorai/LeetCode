class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjlist(n+1);
        for (auto& time : times) {
            adjlist[time[0]].push_back({time[1], time[2]});
        }
        vector<int> time(n+1, 1e9);
        time[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        time[k] = 0;
        while (!pq.empty()) {
            int spend = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (spend > time[node]) continue;
            for (auto i : adjlist[node]) {
                if (spend + i.second < time[i.first]) {
                    time[i.first] = spend + i.second;
                    pq.push({time[i.first], i.first});
                }
            }
        }
        int minTime = 0;
        for (int i = 1; i < n+1; i++) {
            if (time[i] == 1e9) return -1;
            minTime = max(minTime, time[i]);
        }
        return minTime;
    }
};