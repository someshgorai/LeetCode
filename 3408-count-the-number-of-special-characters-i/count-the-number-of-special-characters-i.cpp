class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> freq(256, false);
        for (char c : word) {
            if (isupper(c)) {
                freq[c] = true;
            }
            else {
                freq[c] = true;
            }
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (freq['a' + i] && freq['A' + i]) cnt++;
        }
        return cnt;
    }
};