class Solution {
private:
    int backtrack(int idx, int n, vector<bool>& col, vector<bool>& dia1, vector<bool>& dia2) {
        if (idx == n) return 1;
        int cnt = 0;
        for (int c = 0; c < n; c++) {
            int d1 = idx - c + n - 1;
            int d2 = idx + c;
            if (col[c] || dia1[d1] || dia2[d2]) continue;
            col[c] = dia1[d1] = dia2[d2] = true;

            cnt += backtrack(idx + 1, n, col, dia1, dia2);

            col[c] = dia1[d1] = dia2[d2] = false;
        }

        return cnt;
    }
public:
    int totalNQueens(int n) {
        vector<bool> col(n, false), dia1(2*n - 1, false), dia2(2*n - 1, false);
        return backtrack(0, n, col, dia1, dia2);
    }
};