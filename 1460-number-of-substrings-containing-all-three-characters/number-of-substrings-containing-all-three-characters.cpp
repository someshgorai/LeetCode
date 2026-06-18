class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> vis(3, -1);
        int r = 0, l = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            vis[s[i] - 'a'] = i;
            count = count + (1 + *min_element(vis.begin(), vis.end()));
        }
        return count;
    }
};