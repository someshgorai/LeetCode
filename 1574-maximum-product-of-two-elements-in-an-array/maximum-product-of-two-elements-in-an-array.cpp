class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest1 = 0, largest2 = 0;

        for (int i : nums) {
            if (largest1 <= i) {
                largest2 = largest1;
                largest1 = i;
            }
            else if (largest2 <= i) {
                largest2 = i;
            }
        }
        return (largest1 - 1) * (largest2 - 1);
    }
};