class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> vis(26, 0);
        for (char c : s) {
            vis[c-'a']++;
        }

        string mid = "";
        string first = "";
        for (int i = 0; i < 26; i++) {
            if (vis[i] & 1) {
                char c = 'a' + i;
                int len = (vis[i]-1)/2;

                string s1(len, c);
                first = first + s1;
                mid = c;
            }
            else {
                char c = 'a' + i;
                int len = vis[i]/2;

                string s1(len, c);
                first = first + s1;
            }
        }

        string second = first;
        reverse(second.begin(), second.end());

        return first + mid + second;
    }
};