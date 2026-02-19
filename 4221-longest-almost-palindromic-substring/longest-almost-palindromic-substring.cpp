class Solution {
private:
    int palindromicLen(int left, int right, int n, string s) {
        int maxi = 0;
        while (left >= 0 && right < n) {
            if (s[left] == s[right]) {
                left--;
                right++;
            }
            else break;
        }
        maxi = right - left - 1;

        if (maxi == n) return n ;

        int left1 = left - 1;
        int right1 = right;
        while (left1 >= 0 && right1 < n) {
            if (s[left1] == s[right1]) {
                left1--;
                right1++;
            }
            else break;
        }
        maxi = max(maxi, right1 - left1 - 1);

        int left2 = left;
        int right2 = right + 1;
        while (left2 >= 0 && right2 < n) {
            if (s[left2] == s[right2]) {
                left2--;
                right2++;
            }
            else break;
        }
        maxi = max(maxi, right2 - left2 - 1);

        return maxi;
    }
public:
    int almostPalindromic(string s) {
        int n=s.size();
        int maxlen = 0;
        for (int i = 0; i < n; i++) {
            // Even Center
            maxlen = max(maxlen, palindromicLen(i, i+1, n, s));
            // Odd Center
            maxlen = max(maxlen, palindromicLen(i, i, n, s));
        }
        return maxlen;
    }
};