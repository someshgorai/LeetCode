class Solution {
    bool isPresent(string pattern, string word) {
        return word.find(pattern) != string::npos;
    }
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.size();

        int count = 0;
        for (string pattern : patterns) {
            int m = pattern.size();
            if (m <= n && isPresent(pattern, word)) count++; 
        }

        return count;
    }
};