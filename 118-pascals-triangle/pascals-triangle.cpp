class Solution {
private:
    vector<int> generateRow(int row) {
        vector<int> layer;
        layer.push_back(1);
        int cell = 1;
        for (int col = 1; col < row; col++) {
            cell = cell*(row-col);
            cell = cell / col;
            layer.push_back(cell);
        }
        return layer;
    }
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        vector<vector<int>> pascal;

        for (int row = 1; row <= numRows; row++) {
            pascal.push_back(generateRow(row));
        }

        return pascal;
    }
};