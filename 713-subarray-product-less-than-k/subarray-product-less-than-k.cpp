class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int prod = 1, count = 0;

        while (right < n) {
            prod *= nums[right]; // Updation
            while (left < n && prod >= k) {
                prod /= nums[left];
                left++;
            }
            count += (right - left + 1); 
            right++; 
        }

        return count;
    }
};