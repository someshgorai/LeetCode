class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefix(n+1);

        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i]; 
        }

        int maxSum = 0;

        for (int i = 0; i <= n - firstLen; i++) {
            int sum1 = prefix[i+firstLen] - prefix[i];

            for (int j = 0; j <= n - secondLen; j++) {
                if (j+secondLen <= i || i+firstLen <= j) {
                    int sum2 = prefix[j+secondLen] - prefix[j];
                    maxSum = max(maxSum, sum1 + sum2);
                }
            }
        }

        return maxSum;
    }
};