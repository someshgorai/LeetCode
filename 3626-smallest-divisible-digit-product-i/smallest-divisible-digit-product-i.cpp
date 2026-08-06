class Solution {
private:
    long long getDigitProduct(int num) {
        long long prod = 1;

        while (num) {
            int digit = num % 10;
            num /= 10;
            prod *= digit;
            if (prod == 0) return 0;
        }

        return prod;
    }
public:
    int smallestNumber(int n, int t) {
        int start = n;
        while (true) {
            long long digitProduct = getDigitProduct(start);
            if (digitProduct % t == 0) {
                return start;
            }
            start++;
        }

        return -1;
    }
};