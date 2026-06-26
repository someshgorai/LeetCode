class Solution {
private:
    int findOneBits(int num) {
        int cnt = 0;
        while (num) {
            cnt += (num & 1);
            num >>= 1;
        }
        return cnt;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto comparator = [&](int &a, int &b) {
            int a_bits = findOneBits(a);
            int b_bits = findOneBits(b);

            if (a_bits == b_bits) return a < b;
            return a_bits < b_bits;
        };
        sort(arr.begin(), arr.end(), comparator);
        return arr;
    }
};