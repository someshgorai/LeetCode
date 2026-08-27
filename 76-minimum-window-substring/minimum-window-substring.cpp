class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        unordered_map<char, int> freq;
        for (char c : t) {
            freq[c]++;
        }

        int minLen = 1e9, start = -1;
        int l = 0;
        for (int r = 0; r < n; r++) {
            if (freq[s[r]] > 0) m--;
            freq[s[r]]--;

            while (l <= r && m == 0) {
                if (minLen > r - l + 1) {
                    start = l;
                    minLen = r - l + 1;
                }

                freq[s[l]]++;

                if (freq[s[l]] > 0) {
                    m++;
                }
                
                l++;
            }
        }

        if (start == -1) return "";
        return s.substr(start, minLen);
    }
};