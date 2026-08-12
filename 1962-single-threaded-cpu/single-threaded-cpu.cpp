class Solution {
public:
    typedef pair<int, int> P;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) {
            int at = tasks[i][0];
            int bt = tasks[i][1];
            jobs.push_back({at, bt, i});
        }

        sort(jobs.begin(), jobs.end());

        long long t = 0;
        int i = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> order;

        while (i < n || !pq.empty()) {
            if (pq.empty()) t = max(t, 1LL * jobs[i][0]);

            while (i < n && jobs[i][0] <= t) {
                int bt = jobs[i][1];
                int process = jobs[i][2];

                pq.push({bt, process});
                i++;
            }

            auto [bt, process]= pq.top();
            pq.pop();

            t += bt;
            order.push_back(process);
        }

        return order;
    }
};