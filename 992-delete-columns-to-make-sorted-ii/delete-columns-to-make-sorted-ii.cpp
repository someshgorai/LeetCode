class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs[0].size(), n = strs.size();
        vector<bool> order(n-1, false);
        int ops = 0, j, i;
        for (j=0; j<m; j++) {
            for (i=0; i<n-1; i++) {
                if (!order[i] && strs[i][j] > strs[i+1][j]) {
                    ops++;
                    break;
                }
            }

            if (i < n-1) continue;
            for (i=0; i<n-1; i++) {
                order[i] = order[i] || strs[i][j] < strs[1+i][j];
            }
        }
        return ops;
    }
};