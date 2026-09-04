class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> merge;
        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0]) {
            merge.push_back(intervals[i]);
            i++;
        } 

        int start = newInterval[0];
        int end   = newInterval[1];
        while (i < n && intervals[i][0] <= newInterval[1]) {
            start = min(start, intervals[i][0]);
            end   = max(end, intervals[i][1]);
            i++;
        }

        merge.push_back({start, end});

        while (i < n) {
            merge.push_back(intervals[i]);
            i++;
        }

        return merge;
    }
};