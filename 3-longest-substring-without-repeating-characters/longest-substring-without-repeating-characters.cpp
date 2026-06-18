class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0, maxLen = 0;
        vector<bool> vis(256, false);
        while (right < n) {
            while (vis[s[right]]) {
                vis[s[left]] = false;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            vis[s[right]] = true;
            right++;
        }
        return maxLen;
    }
};