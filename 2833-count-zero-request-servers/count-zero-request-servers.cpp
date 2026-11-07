class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });


        int m = queries.size(), l = logs.size();
        vector<pair<int, int>> queryPair(m);
        for (int i = 0; i < m; i++) {
            queryPair.push_back({queries[i], i});
        }
        sort(queryPair.begin(), queryPair.end());
        vector<int> ans(m);
        unordered_map<int, int> freq;
        int cnt = 0;
        int i = 0, j = 0;
        for (auto &[query, pos] : queryPair) {
            int start = query - x;
            int end   = query;

            while (j < l && logs[j][1] <= end) {
                if (freq[logs[j][0]] == 0) cnt++;
                freq[logs[j][0]]++;
                j++;
            }
            while (i < l && logs[i][1] < start) {
                if (freq[logs[i][0]] == 1) cnt--;
                freq[logs[i][0]]--;
                i++;
            }
            ans[pos] = n - cnt;
        }
        cout << i << ' ' << j ;
        return ans;
    }
};