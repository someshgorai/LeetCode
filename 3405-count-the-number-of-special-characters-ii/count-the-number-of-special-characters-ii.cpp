class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, 1e6), upper(26, -1);
        int n = word.size();

        for (int i = 0; i < n; i++) {
            if (islower(word[i])) {
                lower[word[i] - 'a'] = i;
            }
            else {
                if (upper[word[i] - 'A'] == -1) {
                    upper[word[i] - 'A'] = i;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (upper[i] > lower[i]) cnt++;
        }

        return cnt;
    }
};