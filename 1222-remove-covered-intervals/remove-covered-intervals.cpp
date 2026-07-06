class Solution {
public:
    static bool lamda (vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] <= b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), lamda);
        int n = intervals.size();

        int j = 0, cnt = 0;
        for (int i = 1; i < n; i++) {
            if (intervals[j][1] >= intervals[i][1]) {
                cnt++;
            }
            else j = i;
        }
        return n - cnt;
    }
};