class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<bool> prev(n+1, false);

        prev[0] = true;

        for (int idx = n - 1; idx >= 0; idx--) {
            vector<bool> curr(n+1, false);

            for (int cnt = n - 1; cnt >= 0; cnt--) {

                if (s[idx] == '(') {
                    curr[cnt] = prev[cnt + 1];
                }
                else if (s[idx] == ')') {
                    if (cnt > 0)
                        curr[cnt] = prev[cnt - 1];
                }
                else {
                    if (cnt + 1 <= n)
                        curr[cnt] = prev[cnt + 1];

                    curr[cnt] = curr[cnt] || prev[cnt];

                    if (cnt > 0)
                        curr[cnt] = curr[cnt] || prev[cnt - 1];
                }
            }
            swap(curr, prev);
        }

        return prev[0];
    }
};