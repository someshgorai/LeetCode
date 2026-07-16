class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixGCD(n);
        int maxEle = 0; 
        for (int i = 0; i < n; i++) {
            maxEle = max(maxEle, nums[i]);
            prefixGCD[i] = __gcd(maxEle, nums[i]);
        }

        sort(prefixGCD.begin(), prefixGCD.end());

        int i = 0, j = n-1;
        long long sum = 0;
        while (i < j) {
            sum += __gcd(prefixGCD[i], prefixGCD[j]);
            i++;
            j--;
        }

        return sum;
    }
};