class Solution {
private:
    int getMaxElement(vector<vector<int>>& mat, int col) {
        int m = mat.size();
        int maxi = INT_MIN;
        int idx = 0;
        for (int i = 0; i < m; i++) {
            if (maxi < mat[i][col]) {
                maxi = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat[0].size(), m = mat.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (high - low)/2 + low;
            int maxIdx = getMaxElement(mat, mid);

            int val = mat[maxIdx][mid];
            int left = mid-1 >= 0 ? mat[maxIdx][mid-1] : -1;
            int right = mid + 1 < n? mat[maxIdx][mid+1] : -1;

            if (val > left && val > right) return {maxIdx, mid};
            else if(val < left) high = mid - 1;
            else low = mid + 1;
        }

        return {-1, -1};
    }
};