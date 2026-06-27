class Solution {
public:
    int mod = 1e9+7;
    typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {
        ll aXORx = 0;
        ll bXORx = 0;

        for (int i = 49; i >= n; i--) {
            aXORx = aXORx ^ (a & (1ll << i));
            bXORx = bXORx ^ (b & (1ll << i));
        }

        for (int i = n-1; i >= 0; i--) {
            ll ith_a = a & (1ll << i);
            ll ith_b = b & (1ll << i);
            if (ith_a == ith_b) {
                aXORx = aXORx ^ (1ll << i);
                bXORx = bXORx ^ (1ll << i);
            }
            else {
                if (aXORx >= bXORx) {
                    bXORx = bXORx ^ (1ll << i);
                }
                else {
                    aXORx = aXORx ^ (1ll << i);
                }
            }
        }

        return ((aXORx % mod) * (bXORx % mod))%mod;
    }
};