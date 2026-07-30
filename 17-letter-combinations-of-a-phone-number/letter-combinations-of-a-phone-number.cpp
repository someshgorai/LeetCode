class Solution {
private:
    void backtrack(string digits, vector<string> &res, vector<string> &mp, int idx, int n, string word) {
        if (idx >= n) {
            res.push_back(word);
            return;
        }

        for (char c : mp[digits[idx] - '0']){
            backtrack(digits, res, mp, idx+1, n, word+c);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mp = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        int n = digits.size();
        vector<string> res;
        backtrack(digits, res, mp, 0, n, "");
        return res;
    }
};