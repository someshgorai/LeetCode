class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> freqAlpha(26, 0), freqDigit(10, 0);
        for (char c : s) {
            if (isdigit(c)) {
                freqDigit[c - '0']++;
            }
            if (isalpha(c)) {
                freqAlpha[c - 'a']++;
            }
        }
        int sum = 0;
        for (int i = 0; i < 13; i++) {
            sum += abs(freqAlpha[i] - freqAlpha[25 - i]);
        }
        for (int i = 0; i < 5; i++) {
            sum += abs(freqDigit[i] - freqDigit[9 - i]);
        }
        return sum;
    }
};