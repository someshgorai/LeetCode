class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower = 0;
        int upper = 0;
        for (char c : word) {
            if (islower(c)) {
                lower |= (1 << (c - 'a'));
            }
            else {
                upper |= (1 << (c - 'A'));
            }
        }
        int common = lower & upper;
        return __builtin_popcount(common);
    }
};