class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),
             [](auto &a, auto &b) {
                 return a[0] < b[0];
             });

        int n = events.size();

        // Extract start times for binary search
        vector<int> starts(n);
        for (int i = 0; i < n; i++) {
            starts[i] = events[i][0];
        }

        vector<vector<int>> dp(n + 1, vector<int>(3, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int e = 0; e < 2; e++) {
                // Skip
                int skip = dp[idx + 1][e];

                // Pick
                int next = upper_bound(
                    starts.begin() + idx + 1,
                    starts.end(),
                    events[idx][1]
                ) - starts.begin();

                int pick = events[idx][2] + dp[next][e + 1];

                dp[idx][e] = max(skip, pick);
            }
        }

        return dp[0][0];
    }
};
