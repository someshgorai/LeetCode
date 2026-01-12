class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> pse(n, -1);
        int maxArea = 0;
        for (int i=0; i<n; i++) {
            
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int idx = st.top();
                maxArea = max(maxArea, heights[idx] * (i - pse[idx] - 1));               
                st.pop();
            }
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        while (!st.empty()) {
            maxArea = max(maxArea, heights[st.top()] * (n - pse[st.top()] - 1));
            st.pop();
        }

        return maxArea;
    }
};