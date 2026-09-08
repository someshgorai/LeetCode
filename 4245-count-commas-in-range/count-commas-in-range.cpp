class Solution {
public:
    int countCommas(int n) {
        return n - 1e3 >= 0 ? n - 1e3 + 1 : 0;
    }
};