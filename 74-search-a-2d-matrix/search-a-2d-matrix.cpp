class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int low = 0, high = m - 1;
        while (low <= high) {
            int mid = ((high - low)/2) + low;

            if (matrix[mid][0] == target) return true;

            if (matrix[mid][0] > target) high = mid - 1;
            else low = mid + 1;
        }
        
        if (low == 0) return false;

        int row = low - 1;
        low = 0;
        high = n - 1;

        while (low <= high) {
            int mid = (high - low)/2 + low;

            if (matrix[row][mid] == target) return true;

            if (matrix[row][mid] > target) high = mid - 1;
            else low = mid + 1;
        } 

        return false;
    }
};