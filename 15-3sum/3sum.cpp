class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> st;

        for (int i = 0; i < n; i++) {
            int left = nums[i];
            
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int mid   = nums[j];
                int right = nums[k];

                if (left + mid + right == 0) {
                    st.insert({left, mid, right});
                    j++;
                    k--;
                }
                else if (left + mid + right > 0)  k--;
                else j++;  
            }
        }

        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};