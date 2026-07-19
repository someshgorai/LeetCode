class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> vis(26, false);
        vector<int> lastSeen(26);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i;
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            while (!ans.empty() && ans.back() > s[i] && lastSeen[ans.back() - 'a'] > i && !vis[s[i]-'a']) {
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            if (!vis[s[i] - 'a']) {
                ans.push_back(s[i]);
                vis[s[i]-'a'] = true;
            }
        }

        return ans;        
    }
};