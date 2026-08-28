class Solution {
private:
    string res = "";
    bool backtrack(int idx, int n, bool isGreater, string &target, string &str, vector<int> &freq) {
        if (idx == n) {
            if (isGreater) {
                res = str;
                return true;
            }
            return false;
        }

        bool greater = isGreater;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freq[ch - 'a'] == 0) continue;
            if (!isGreater && ch < target[idx]) continue;

            str += ch;
            freq[ch - 'a']--;
            greater = isGreater || ch > target[idx];

            if (backtrack(idx+1, n, greater, target, str, freq)) return true;

            str.pop_back();
            freq[ch - 'a']++;
            greater = isGreater;
        }

        return false;
    }
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        string str = "";
        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        bool isPossible = backtrack(0, n, false, target, str, freq);
        return isPossible == true ? res : "";
    }
};