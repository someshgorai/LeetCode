class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();

        vector<int> heights(m, 0);  
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            // Step 1: Update histogram heights for current row
            for (int j = 0; j < m; j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }

            // Step 2: Largest Rectangle in Histogram (inline version)
            stack<int> st;
            for (int j = 0; j <= m; j++) {
                while (!st.empty() && (j == m || heights[st.top()] > heights[j])) {
                    int height = heights[st.top()];
                    st.pop();
                    int width = st.empty() ? j : j - st.top() - 1;
                    maxArea = max(maxArea, width * height);
                }
                st.push(j);
            }
        }

        return maxArea;
    }
};


