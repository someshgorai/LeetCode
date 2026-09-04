class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merge;
        merge.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            vector<int> prev = merge.back();

            if (prev[0] <= intervals[i][0] && intervals[i][0] <= prev[1]) {
                int start = prev[0];
                int end = max(intervals[i][1], prev[1]);

                merge.pop_back();
                merge.push_back({start, end});
            }
            else {
                merge.push_back(intervals[i]);
            }
        }

        return merge;
    }
};