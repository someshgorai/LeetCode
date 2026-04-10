class Solution {
long long MOD = 1e9+7;
private:
    long long power(long long a, long long b) {
        if (b == 0) {
            return 1;
        }

        long long half = power(a, b/2);
        long long result = (1LL * half * half) % MOD;

        if (b & 1) {
            result = (1LL * result * a) % MOD;
        }

        return result;
    }
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int blockSize = ceil(sqrt(n));
        unordered_map<int, vector<vector<int>>> smallKMap;
        vector<int> res = nums;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            if (k >= blockSize) {
                for (int i = l; i <= r; i += k) {
                    res[i] = (1LL * res[i] * v) % MOD;
                }
            }
            else {
                smallKMap[k].push_back(q);
            }
        }

        for (auto &[k, queries] : smallKMap) {
            vector<int> diff(n, 1);
            for (auto &q : queries) {
                int l = q[0];
                int r = q[1];
                int v = q[3];

                diff[l] = (1LL *diff[l] * v) % MOD;

                int steps = (r - l)/k;
                int next  = l + (steps+1) * k;

                if (next < n) diff[next] = (1LL * diff[next] * power(v, MOD-2)) % MOD; 
            }

            // Cummulative Product
            for (int i = 0; i < n; i++) {
                if (i >= k) diff[i] = (1LL * diff[i] * diff[i-k]) % MOD;
            }

            for (int i = 0; i < n; i++) {
                res[i] = (1LL * diff[i] * res[i]) % MOD;
            }
        }

        int ans = res[0];
        for (int i = 1; i < n; i++) {
            ans ^= res[i];
        }
        return ans;
    }
};