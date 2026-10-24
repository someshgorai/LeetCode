class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};

        vector<int> ans;
        long long cell = 1;

        ans.push_back(1);
        for (int i = 1; i < rowIndex; i++) {
            cell *= (rowIndex - i + 1);
            cell /= (i);
            ans.push_back(cell);
        }
        ans.push_back(1);

        return ans;
    }
};