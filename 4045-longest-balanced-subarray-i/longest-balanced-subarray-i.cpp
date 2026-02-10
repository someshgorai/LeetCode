class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        for (int left=0; left<n; left++) {
            set<int> e, o;
            int odd = 0, even = 0;
            for (int right=left; right<n; right++) {
                if(nums[right] & 1 && o.count(nums[right]) == 0) {
                    odd++;
                    o.insert(nums[right]);
                }
                if(~nums[right] & 1 && e.count(nums[right]) == 0) {
                    even++;
                    e.insert(nums[right]);
                }
                if (odd == even) len = max(len, right - left + 1);
            }  
        }
        return len;
    }
};