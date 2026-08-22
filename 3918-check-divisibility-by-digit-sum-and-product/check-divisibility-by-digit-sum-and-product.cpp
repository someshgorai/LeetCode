class Solution {
private:
    int getDigitSum(int n) {
        int sum = 0;
        while(n) {
            sum += n%10;
            n /= 10;
        }

        return sum;
    }
    int getDigitProd(int n) {
        int prod = 1;
        while(n) {
            prod *= n % 10;
            n /= 10;
        }

        return prod;
    }
public:
    bool checkDivisibility(int n) {
        if (n == 0) return true;

        int sum  = getDigitSum(n);
        int prod = getDigitProd(n);

        return (n % (sum + prod) == 0);
    }
};