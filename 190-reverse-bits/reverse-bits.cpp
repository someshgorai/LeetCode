class Solution {
public:
    int reverseBits(int n) {
        long long bitset = 0;
        int temp = n;
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            res = res | (temp & 1);
            temp >>= 1;
        }
        return res;
    }
};