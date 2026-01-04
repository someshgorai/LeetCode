class Solution {
private:
    int divisors(int n) {
        int cnt = 2, sum = n + 1;
        for (int i=2; i<=(n+1)/2; i++) {
            if (n%i == 0) {
                cnt++;
                sum += i;
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