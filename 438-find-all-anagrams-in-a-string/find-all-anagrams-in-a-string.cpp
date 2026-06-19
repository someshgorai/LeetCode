class Solution {
private:
    bool checkWindow(unordered_map<char, int> &freq) {
        bool ok = true;
        for (auto &it : freq) {
            if (it.second > 0) {
                ok = false;
                break;
            }
        }
        return ok;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> freq;
        vector<int> res;
        for (char c : p) {
            freq[c]++;
        }

        int n = s.size(), j = 0, m = p.size();
        for (int i = 0; i < n; i++) {
            if (freq.find(s[i]) != freq.end()) {
                freq[s[i]]--;
            }
            if (i - j + 1 == m) {
                if (checkWindow(freq)) res.push_back(j);
                if (freq.find(s[j]) != freq.end()) freq[s[j]]++;
                j++;
            }
        }

        return res;
    }
};