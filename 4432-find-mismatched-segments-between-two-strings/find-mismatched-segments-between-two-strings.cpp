class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.size();
        string seg1 = "", seg2 = "";
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                seg1 += s1[i];
                seg2 += s2[i];
            }
            else if (!seg1.empty()) {
                ans.push_back({seg1, seg2});
                seg1 = "";
                seg2 = "";
            }
        }

        if (!seg1.empty()) {
            ans.push_back({seg1, seg2});
        }

        return ans;
    }
};