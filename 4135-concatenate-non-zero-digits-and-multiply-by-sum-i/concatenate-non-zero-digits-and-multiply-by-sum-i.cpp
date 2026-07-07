class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0, sum = 0;
        string temp = to_string(n);
        
        for (char c : temp) {
            if (c - '0') {
                x = x*10 + (c - '0');
                sum += (c - '0');
            }
        }
        return 1LL * x * sum;
    }
};