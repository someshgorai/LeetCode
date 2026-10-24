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
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (k > j && nums[k] == nums[k + 1])
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