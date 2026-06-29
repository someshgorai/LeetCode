class Solution {
    bool isPresent(string pattern, string word, int m, int n) {
        bool present = false;
        for (int i = 0; i < n - m + 1; i++) {
            for (int j = 0; j < m; j++) {
                if (word[j + i] != pattern[j]) break;
                if (j == m-1) present = true;
            }
            if (present) return true;
        }
        return false;
    }
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.size();

        int count = 0;
        for (string pattern : patterns) {
            int m = pattern.size();
            if (m <= n && isPresent(pattern, word, m, n)) count++; 
        }

        return count;
    }
};