class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int j = 0;
        string res = "";
        int ones = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ones++;
                if (ones == 1) j = i;
            }

            if (ones > k) {
                j++;
                ones--;
                while (s[j] == '0') {
                    j++;
                }
            }

            int len = i - j + 1;
            string temp = s.substr(j, len);
            if (ones == k && (res.empty() || res.size() > temp.size() || (res.size() == temp.size() && res > temp))) {
                res = temp;
            }
        }

        return res;
    }
};