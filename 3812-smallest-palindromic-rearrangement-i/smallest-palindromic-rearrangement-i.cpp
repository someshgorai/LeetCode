class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> vis(26, 0);
        for (int i = 0; i < n/2; i++) {
            vis[s[i] - 'a']++;
        }

        string ans = s;
        int left = 0, right = n-1;
        for (int i = 0; i < 26; i++) {
            while (vis[i] > 0) {
                char c = i + 'a';
                ans[left] = c;
                ans[right] = c;
                left++;
                right--;
                vis[i]--;
            }
        }
        return ans;
    }
};