class Solution {
private:
    int solve(int start, int end, string &word, int k) {
        int res = 0;
        int len = end - start + 1;

        for (int uniq = 1; uniq <= 26 && uniq * k <= len; uniq++) {
            int windowLength = uniq * k;

            vector<int> freq(26, 0);
            int distinct = 0;
            int countK = 0;

            int i = start;

            for (int j = start; j <= end; j++) {
                int idx = word[j] - 'a';

                freq[idx]++;

                if (freq[idx] == 1) distinct++;
                if (freq[idx] == k) countK++;
                else if (freq[idx] == k + 1) countK--;

                while (j - i + 1 > windowLength) {
                    idx = word[i] - 'a';

                    if (freq[idx] == k) countK--;
                    else if (freq[idx] == k + 1) countK++;

                    freq[idx]--;

                    if (freq[idx] == 0) distinct--;

                    i++;
                }

                if (j - i + 1 == windowLength &&
                    distinct == uniq &&
                    countK == uniq) {
                    res++;
                }
            }
        }

        return res;
    }

public:
    int countCompleteSubstrings(string word, int k) {
        int n = word.size();
        int ans = 0;

        int start = 0;

        for (int i = 1; i < n; i++) {
            if (abs(word[i] - word[i - 1]) > 2) {
                ans += solve(start, i - 1, word, k);
                start = i;
            }
        }

        ans += solve(start, n - 1, word, k);

        return ans;
    }
};