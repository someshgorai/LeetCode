class Solution {
private:
    int divisors(int n) {
        if (n < 6) return 0; 
        int cnt = 2, sum = n + 1;
        int limit = sqrt(n);
        for (int i=2; i<=limit; i++) {
            if (n%i == 0) {
                int n2 = n/i;
                if (n2 == i) {
                    cnt++;
                    sum += i;
                }
                else {
                    cnt += 2;
                    sum += i + n2;
                }
            }
            if (cnt > 4) return 0;
        }
        if (cnt < 4) return 0;
        return sum;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (int i:nums) {
            sum += divisors(i);
        }
        return sum;
    }
};