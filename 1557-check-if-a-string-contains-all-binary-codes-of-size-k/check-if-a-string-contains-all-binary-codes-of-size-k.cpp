class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (n < k) return false;

        int m = 1 << k;
        unordered_set<string> vis;

        int count = 0;
        for (int i = 0; i <= n - k; i++) {
            string code = s.substr(i, k);
            if (vis.count(code) == 0) count++;
            if (count == m) return true;
            vis.insert(code);
        }
        return vis.size() == m;
    }
};