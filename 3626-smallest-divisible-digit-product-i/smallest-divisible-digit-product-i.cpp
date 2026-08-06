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
        int i;
        for (i = n; i % 10 != 0; i++) {
            long long digitProduct = getDigitProduct(i);

            if (digitProduct % t == 0) return i;
        }

        return i;
    }
};