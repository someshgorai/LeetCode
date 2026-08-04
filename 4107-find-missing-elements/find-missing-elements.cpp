class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st;
        for (int i : nums) st.insert(i);

        int n = *min_element(nums.begin(), nums.end());
        int m = *max_element(nums.begin(), nums.end());

        vector<int> res;
        for (int i = n; i <= m; i++) {
            if (st.find(i) == st.end()) res.push_back(i);
        }

        return res;
    }
};