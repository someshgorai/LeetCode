class Solution {
    unordered_map<string, bool> memo;
    unordered_map<string, vector<char>> mp;

    bool dfs(string curr) {
        if (curr.size() == 1) return true;
        if (memo.count(curr)) return memo[curr];

        int n = curr.size();
        vector<vector<char>> choices(n - 1);

        // Build choices for each adjacent pair
        for (int i = 0; i < n - 1; i++) {
            string key = curr.substr(i, 2);
            if (!mp.count(key)) {
                memo[curr] = false;
                return false;
            }
            choices[i] = mp[key];
        }

        // Backtracking to generate next rows
        function<bool(int, string&)> build = [&](int idx, string &next) {
            if (idx == n - 1)
                return dfs(next);

            for (char c : choices[idx]) {
                next.push_back(c);
                if (build(idx + 1, next)) return true;
                next.pop_back();
            }
            return false;
        };

        string next;
        bool res = build(0, next);
        memo[curr] = res;
        return res;
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed) {
            mp[s.substr(0,2)].push_back(s[2]);
        }
        return dfs(bottom);
    }
};
