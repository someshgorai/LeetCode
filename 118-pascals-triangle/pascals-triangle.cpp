class Solution {
private:
    int get_nCr(int n, int r) {
        long long res = 1;
        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (long long)(i+1);
        }
        return (int)res;
    }
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        vector<vector<int>> pascal(numRows);
        pascal[0].push_back(1);

        for (int row = 1; row < numRows; row++) {
            for (int col = 0; col <= row; col++) {
                pascal[row].push_back(get_nCr(row, col));
            }
        }

        return pascal;
    }
};