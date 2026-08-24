class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long long ans = 0, i = 0;
        bool sign = true;
        while (isspace(s[i])) {
            i++;
        }

        if (s[i] == '-') {
            sign = false;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }
        long long limit = INT_MAX;
        while(isdigit(s[i])) {
            int digit = s[i] - '0';
            ans = ans * 10 + digit;
            if (sign && ans >= limit) return INT_MAX;
            if (!sign && ans >= limit+1) return INT_MIN;
            i++;
        }

        if (!sign) return -1 * ans;
        return ans;
    }
};