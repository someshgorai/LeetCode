class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        set<int> free;

        for (int i = 0; i < k; i++) {
            free.insert(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        vector<int> count(k, 0);
        int maxFreqServer;
        int maxCount = 0;

        for (int i = 0; i < n; i++) {
            int startTime = arrival[i];
            int endTime   = load[i] + startTime;

            while (!busy.empty() && busy.top().first <= startTime) {
                int freeServer = busy.top().second;
                busy.pop();
                free.insert(freeServer);
                free.insert(freeServer + k);
            }

            if (free.empty()) continue;

            int freeServer = (*free.lower_bound(i % k)) % k;
            free.erase(freeServer);
            free.erase(freeServer + k);

            busy.push({endTime, freeServer});

            count[freeServer]++;
            maxCount = max(maxCount, count[freeServer]);
        }

        vector<int> busiestServer;
        for (int i = 0; i < k; i++) {
            if (maxCount == count[i]) busiestServer.push_back(i);
        }

        return busiestServer;
    }
};