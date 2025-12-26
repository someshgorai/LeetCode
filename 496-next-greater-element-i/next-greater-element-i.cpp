class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> next;
        stack<int> st;
        vector<int> ans;
        int n =nums1.size(), m = nums2.size();
        for (int i=m-1; i>=0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty()) next[nums2[i]] = -1;
            else next[nums2[i]] = st.top();
            st.push(nums2[i]);
        }

        for (int num:nums1) {
            ans.push_back(next[num]);
        }

        return ans;
    }
};