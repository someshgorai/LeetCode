class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (string &word : words) {
            int res = 0;
            for (char &c : word) {
                res += weights[c - 'a'];
            }
            res = res%26;
            ans += 'a' + 25 - res;
        }
        return ans;   
    }
};