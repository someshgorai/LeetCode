class Solution {
private:
    unordered_set<int> getPrimes(int m) {
        vector<bool> sieve(m+1, true);
        sieve[0] = sieve[1] = false;
        unordered_set<int> primes;

        for (int i = 2; i*i <= m; i++) {
            if (sieve[i]) {
                primes.insert(i);
                for (int j = i*i; j <= m; j += i) {
                    sieve[j] = false;
                }
            }
        }

        for (int i = sqrt(m); i <= m; i++) {
            if (sieve[i]) primes.insert(i);
        }

        return primes;
    }
public:
    int divisibleGame(vector<int>& nums) {
        int mod = 1e9+7;
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        unordered_set<int> primes = getPrimes(m);

        long long maxVal = -*min_element(nums.begin(), nums.end()), k = 2;
        for (int p : primes) {
            long long val = 0;
            for (int i : nums) {
                if (i % p == 0) val += i;
                else val -= i;

                if (val > maxVal) {
                    maxVal = val;
                    k = p;
                    cout << val << ' ' << k << ' ';
                }
                else if (val == maxVal && k > p) {
                    k = p;
                }
                
                if (val < 0) val = 0;
            }
        }
        maxVal = (maxVal % mod + mod) % mod;
        return (maxVal * k) % mod; 
    }
};