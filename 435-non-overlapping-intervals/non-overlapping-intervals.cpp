class Solution {
public:
    struct comparator {
        bool operator() (auto &a, auto &b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        }
    };
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator());

        int n = intervals.size();
        int cnt = 0;
        int lastEndTime = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (lastEndTime > intervals[i][0]) {
                cnt++;
            }
            else {
                lastEndTime = intervals[i][1];
            }
        }

        return cnt;
    }
};