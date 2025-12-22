class Solution {
private:
    bool func(vector<int>& nums, int d, int threshold) {
        int sum = 0;
        for (int i : nums) {
            sum += (i + d - 1)/d;
            if (sum > threshold) return false;
        }
        return true;
    }
public:
    int smallestDivisor(vector<int>& A, int threshold) {
        int left = 1, right = 1e6, m, sum;
        while (left < right) {
            m = (left + right) / 2, sum = 0;
            for (int i : A)
                sum += (i + m - 1) / m;
            if (sum > threshold)
                left = m + 1;
            else
                right = m;
        }
        return left;
    }
};