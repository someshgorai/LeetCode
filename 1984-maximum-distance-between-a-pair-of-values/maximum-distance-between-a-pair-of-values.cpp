class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = n1 - 1, j = n2 - 1;
        int maxdist = 0;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                j--;
            }
            else {
                maxdist = max(maxdist, j - i);
                i--;
            }
        } 
       
        return maxdist;
    }
};