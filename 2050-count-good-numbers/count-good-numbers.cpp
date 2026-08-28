class Solution {
private:
    int mod = 1e9 + 7;
    int power(long long n, long long p) {
        if (p == 0) return 1;
        if (p == 1) return n;

        if (p & 1) return n * power(n, p - 1) % mod;
        return power(n * n % mod, p / 2) % mod;
    }
public:
    int countGoodNumbers(long long n) {
        if (n & 1) {
            return (int)(5LL * power(20, (n-1) / 2) % mod);
        }

        return power(20, n / 2) % mod;
    }
};