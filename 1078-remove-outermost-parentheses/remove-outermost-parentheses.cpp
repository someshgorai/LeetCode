class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans = "";
        int brackets = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (brackets == 0) start = i;
                brackets++;
            }
            else brackets--;

            if (brackets == 0) {
                ans += s.substr(start + 1, i - start - 1);
            }
        }

        return ans;
    }
};