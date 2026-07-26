class Solution {
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long nCr(int n, int r, vector<long long> &fact, vector<long long> &invFact) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

public:
    int countValidSequences(int n, int k) {
        if (k > n) return 0;

        vector<long long> fact(n + 1), invFact(n + 1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = modPow(fact[n], MOD - 2);
        for (int i = n; i >= 1; i--)
            invFact[i - 1] = invFact[i] * i % MOD;

        long long total = nCr(n - 1, k - 1, fact, invFact);

        long long odd = 0;
        if ((n - k) % 2 == 0) {
            int m = (n - k) / 2;
            odd = nCr(m + k - 1, k - 1, fact, invFact);
        }

        return (total - odd + MOD) % MOD;
    }
};