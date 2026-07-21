class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> lastS(256, -1);
        vector<int> lastT(256, -1);
        if (s.size() != t.size()) return false;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (lastS[s[i]] != lastT[t[i]]) {
                return false;
            }
            lastS[s[i]] = i;
            lastT[t[i]] = i;
        }

        return true;
    }
};