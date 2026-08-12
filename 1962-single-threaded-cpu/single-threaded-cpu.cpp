class Solution {
public:
    typedef pair<int, int> P;
    typedef long long ll;

    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push({tasks[i][0], tasks[i][1], i});
        }

        ll t = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> order;

        while (!jobs.empty() || !pq.empty()) {

            if (pq.empty())
                t = max(t, jobs.top()[0]);

            while (!jobs.empty() && jobs.top()[0] <= t) {
                auto job = jobs.top();
                jobs.pop();

                pq.push({job[1], job[2]});
            }

            auto [bt, process] = pq.top();
            pq.pop();

            t += bt;
            order.push_back(process);
        }

        return order;
    }
};