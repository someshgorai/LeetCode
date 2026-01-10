class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        unordered_set<string> beginSet{beginWord}, endSet{endWord};
        int level = 1;
        int L = beginWord.size();

        while (!beginSet.empty() && !endSet.empty()) {
            // Always expand the smaller set
            if (beginSet.size() > endSet.size())
                swap(beginSet, endSet);

            unordered_set<string> nextLevel;

            for (string word : beginSet) {
                for (int i = 0; i < L; i++) {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if (endSet.count(word)) return level + 1;
                        if (dict.count(word)) {
                            nextLevel.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }

            beginSet = move(nextLevel);
            level++;
        }
        return 0;
    }
};
