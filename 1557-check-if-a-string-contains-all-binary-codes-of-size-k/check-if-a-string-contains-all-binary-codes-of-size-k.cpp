class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (n < k) return false;

        int m = 1 << k;
        unordered_set<string> vis;

        for (int i = 0; i <= n - k; i++) {
            vis.insert(s.substr(i, k));
        }
        return vis.size() == m;
    }
};