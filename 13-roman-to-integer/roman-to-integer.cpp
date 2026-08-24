class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0, level = 1;
        int i = n-1;

        while (i >= 0) {
            if (s[i] == 'I') {
                if (level == 1) {
                    ans += 1;
                }
                else ans -= 1;
            }

            if (s[i] == 'V') {
                ans += 5;
                level = 5;
            }

            if (s[i] == 'X') {
                if (level <= 10) {
                    ans += 10;
                    level = 10;
                }
                else ans -= 10;
            } 

            if (s[i] == 'L') {
                ans += 50;
                level = 50;
            }

            if (s[i] == 'C') {
                if (level <= 100) {
                    ans += 100;
                    level = 100;
                }
                else ans -= 100;
            }

            if (s[i] == 'D') {
                ans += 500;
                level = 500;
            }

            if (s[i] == 'M') {
                ans += 1000;
                level = 1000;
            }

            i--;
        } 

        return ans;
    }
};