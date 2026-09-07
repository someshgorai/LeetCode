class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(26, 0);
        int cnt = 0;
        int mod = 1e9 + 7;

        for (char c : s) {
            int add = (cnt + 1 - dp[c - 'a'] + mod) % mod;
            dp[c - 'a'] = (cnt + 1) % mod;
            cnt = (cnt + add) % mod;
        }

        return cnt;
    }
};