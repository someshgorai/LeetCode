class Solution {
public:
    int minOperations(string s) {
        int mn = *min_element(s.begin(), s.end());
        int mx = *max_element(s.begin(), s.end());
        if (is_sorted(s.begin(), s.end())) return 0;
        int n  = s.size();

        if (n == 2) return -1;
        if (mn == s[0] || mx == s[n-1]) return 1;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }

        return 3;
    }
};