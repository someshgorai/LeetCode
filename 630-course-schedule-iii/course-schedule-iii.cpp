class Solution {
public:
    static auto lambda(const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), lambda);

        int cnt = 0;
        int currDay = 0;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            int dura = courses[i][0];
            int last = courses[i][1];
            if (last >= currDay + dura) {
                currDay = currDay + dura;
                cnt++;
                pq.push({dura, last});
            }
            else if (!pq.empty()) {
                auto it = pq.top();

                if (dura < it.first) {
                    pq.pop();
                    pq.push({dura, last});
                    currDay += dura - it.first;
                }
            }
        }

        return cnt;
    }
};