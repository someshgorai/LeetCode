class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        q.emplace(beginWord, 1);
        while (!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            
            for (int i=0; i<word.size(); i++) {
                char original = word[i];
                for (char ch='a'; ch<='z'; ch++) {
                    word[i] = ch;
            
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.emplace(word, step+1);
                        if (word == endWord) return step+1;
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};