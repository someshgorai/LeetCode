class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0, temp = n;
        while (temp) {
            rev = (temp%10) + rev * 10;
            temp = temp/10;
        }
        return abs(n-rev);
    }
};