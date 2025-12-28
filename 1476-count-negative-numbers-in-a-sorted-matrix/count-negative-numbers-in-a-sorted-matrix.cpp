class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int neg = 0;

        for (auto &row : grid) {
            int l = 0, r = n - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (row[mid] < 0) r = mid - 1;
                else l = mid + 1;
            }
            neg += n - l; 
        }
        return neg;
    }
};
