class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long sum = 0, sqSum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
                sqSum += (long long)grid[i][j] * (long long)grid[i][j];
            }
        }

        long long limit = n * n;
        long long s1 = (limit) * (limit + 1) / 2;
        long long s2 = (limit) * (limit + 1)  * (2 * limit + 1) / 6;
        long long val1 = sum - s1;
        long long val2 = sqSum - s2;
        val2 = val2 / val1;

        int x = (val1 + val2) / 2;
        int y = (val2 - val1) / 2;

        return {x, y};
    }
};