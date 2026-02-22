class Solution {
public:
    string maximumXor(string s, string t) {
        int n = t.size();
        int ones = 0, zeros = 0;
        for (char &bit : t) {
            if (bit == '1') ones++;
            else zeros++;
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (zeros > 0) {
                    ans += '1';
                    zeros--;
                }
                else {
                    ans += '0';
                    ones--;
                }
            }
            if (s[i] == '0') {
                if (ones > 0) {
                    ans += '1';
                    ones--;
                }
                else {
                    ans += '0';
                    zeros--;
                }
            }
        }
        return ans;
    }
};