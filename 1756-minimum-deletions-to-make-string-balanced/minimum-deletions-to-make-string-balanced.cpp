class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int delCount = 0;
        for (char &c : s) {
            if (!st.empty() && st.top() == 'b' && c == 'a') {
                st.pop();
                delCount++;
            }
            else st.push(c);
        }
        return delCount;
    }
};