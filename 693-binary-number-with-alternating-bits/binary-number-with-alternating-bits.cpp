class Solution {
public:
    bool hasAlternatingBits(int n) {
        int res = n ^ (n >> 1);
        return ((long long)res & ((long long)res + 1)) == 0 ? true : false;
    }
};