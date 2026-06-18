class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> vis(256, false);
            for (int j = i; j < n; j++) {
                if (vis[s[j]] == false) {
                    maxLen = max(maxLen, j - i + 1);
                    vis[s[j]] = true;
                }
                else {
                    break;
                }
            }
        }
        return maxLen;
    }
};