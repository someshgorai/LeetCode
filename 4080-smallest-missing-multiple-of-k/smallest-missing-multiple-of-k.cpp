class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;

        for(int i : nums) {
            st.insert(i);
        }

        for (int i = 1; i <= n; i++) {
            int mul = i * k;
            if (st.find(mul) == st.end()) return mul;
        }

        return (n+1) * k;
    }
};