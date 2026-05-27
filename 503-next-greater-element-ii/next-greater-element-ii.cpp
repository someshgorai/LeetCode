class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n, -1);

        for (int i = n-1; i >= 0; i--) {
            st.push(nums[i]);
        }

        for (int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[i] >= st.top()) {
                st.pop();
            }
            if (!st.empty()) nge[i] = st.top();
            st.push(nums[i]);
        }

        return nge;
    }
};