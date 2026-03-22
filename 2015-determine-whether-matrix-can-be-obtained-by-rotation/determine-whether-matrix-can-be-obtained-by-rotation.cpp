class Solution {
private:
    vector<vector<int>> rotate(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<vector<int>> rmat(n, vector<int> (n));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                rmat[i][j] = mat[j][i];
                rmat[j][i] = mat[i][j];
            }
            rmat[i][i] = mat[i][i];
        }

        for (int i = 0; i < n; i++) {
            reverse(rmat[i].begin(), rmat[i].end());
        }

        return rmat;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {
            if (mat == target) return true;
            mat = rotate(mat);  
        }
        return false;
    }
};