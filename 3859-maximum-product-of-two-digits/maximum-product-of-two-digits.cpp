class Solution {
public:
    int maxProduct(int n) {
        int max1 = 0, max2 = 0;
        vector<int> digits;

        while (n) {
            int i = n % 10;
            if (i > max1) {
                max2 = max1;
                max1 = i;
            }
            else if (max1 >= i && max2 < i) {
                max2 = i;
            }
            n = n / 10;
        }

        return max1 * max2;
    }
};