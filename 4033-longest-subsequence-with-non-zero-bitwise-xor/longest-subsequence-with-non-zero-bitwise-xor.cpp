class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool isAllZeros = true;
        int x = 0;
        for (int i : nums) {
            if (i != 0) isAllZeros = false;
            x ^= i;
        }

        if (isAllZeros) return 0;
        if (x == 0) return n-1;
        return n;
    }
};