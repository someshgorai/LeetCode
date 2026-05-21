class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> nums;

        int i = 0, j = 0;
        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                nums.push_back(nums1[i]);
                i++;
            }
            else {
                nums.push_back(nums2[j]); 
                j++;
            }
        }

        while (i < n) {
            nums.push_back(nums1[i]);
            i++;
        }

        while (j < m) {
            nums.push_back(nums2[j]);
            j++;
        }

        int l = n + m;
        if (l & 1) return nums[l/2];
        return (double)(nums[l/2] + nums[l/2 - 1])/2;
    }
};