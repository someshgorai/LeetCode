class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int l1 = -1e9, l2 = -1e9, l3 = -1e9;
        int s1 = 1e9, s2 = 1e9;

        for (int i = 0; i < n; i++) {
            if (l1 <= nums[i]) {
                l3 = l2;
                l2 = l1;
                l1 = nums[i];
            }
            else if (l2 <= nums[i]) {
                l3 = l2;
                l2 = nums[i];
            }
            else if (l3 <= nums[i]) {
                l3 = nums[i];
            }

            if (s1 >=  nums[i]) {
                s2 = s1;
                s1 = nums[i];
            }
            else if (s2 >= nums[i]) {
                s2 = nums[i];
            }
        }

        return max(l1 * l2 * l3, s1 * s2 * l1);
    }
};