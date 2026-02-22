class Solution {
private:
    int factorial(int n) {
        int res = 1;
        for (int i = 2; i <= n; i++) res *= i;
        return res;
    }
public:
    bool isDigitorialPermutation(int n) {
        int factorialSum = 0;
        int temp = n;
        vector<int> freq(10, 0);
        while (temp > 0) {
            factorialSum += factorial(temp % 10);
            freq[temp % 10]++;
            temp /= 10;
        }
        while (factorialSum > 0) {
            freq[factorialSum % 10]--;
            factorialSum /= 10;
        }
        for (int i : freq) {
            if (i != 0) return false;
        }
        return true;
    }
};