class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> free;
        priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<>> service;

        for (int i = 0; i < n; i++) {
            free.push({servers[i], i});
        }

        long long time = 0;
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            time = max(time, (long long)i);

            if (free.empty()) time = service.top().first;

            while (!service.empty() && service.top().first <= time) {
                auto temp = service.top();
                service.pop();
                free.push(temp.second);
            }

            pair<int, int> freeServer = free.top();
            free.pop();
            service.push({time + tasks[i], freeServer});
            ans[i] = freeServer.second;
        }

        return ans;
    }
};