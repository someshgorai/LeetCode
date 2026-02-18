class Solution {
public:
    bool hasAlternatingBits(int n) {
        int temp = n;
        bool alter = false;
        if (n & 1) alter = true;
        while (temp != 0) {
            int bit = temp & 1;
            if (bit ^ alter != 0) return false;
            temp = temp >> 1;
            alter = !alter;
        }
        return true;
    }
};