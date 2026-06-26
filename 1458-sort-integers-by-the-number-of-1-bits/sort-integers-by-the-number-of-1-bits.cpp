class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto comparator = [&](int &a, int &b) {
            int a_bits = __builtin_popcount(a);
            int b_bits = __builtin_popcount(b);

            if (a_bits == b_bits) return a < b;
            return a_bits < b_bits;
        };
        sort(arr.begin(), arr.end(), comparator);
        return arr;
    }
};