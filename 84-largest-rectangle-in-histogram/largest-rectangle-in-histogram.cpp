class Solution {
private:
    vector<int> getNSE(vector<int> &heights) {
        int n = heights.size();
        vector<int> res(n, n);
        stack<int> st;
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) 
            res[i] = st.top();;
            st.push(i);
        }
        return res;
    }
    vector<int> getPSE(vector<int> &heights) {
        int n = heights.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) res[i] = st.top();;
            st.push(i);
        }
        return res;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = getNSE(heights);
        vector<int> pse = getPSE(heights);
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, heights[i] * (nse[i] - pse[i] - 1));
        }

        return maxArea;
    }
};