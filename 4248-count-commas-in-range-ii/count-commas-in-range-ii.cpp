class Solution {
public:
    long long countCommas(long long n) {
        long long ulimit = 1000;
        long long cnt = 0;

        while (n >= ulimit) {
            cnt += (n - ulimit + 1);
            ulimit *= 1000;
        }

        return cnt;
    }
};