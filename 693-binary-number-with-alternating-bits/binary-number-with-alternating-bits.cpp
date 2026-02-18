class Solution {
public:
    bool hasAlternatingBits(int n) {
        return (((long long)(n ^= (n >> 1))) & ((long long)n + 1)) == 0;

    }
};