class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int len = 0;
        string ans;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (len > 0) ans += s.substr(i + 1, len) + ' ';
                len = 0;
            }
            else {
                len++;
            }
        }
        if (len > 0){
            ans += s.substr(0, len) + ' ';
        }
        ans.pop_back();

        return ans;
    }
};