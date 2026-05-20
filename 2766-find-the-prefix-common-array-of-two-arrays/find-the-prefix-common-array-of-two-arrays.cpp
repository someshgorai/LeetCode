class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> vis(n+1, 0), C(n);

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            if (vis[A[i]] == 0) vis[A[i]]++;
            else cnt++;

            if (vis[B[i]] == 0) vis[B[i]]++;
            else cnt++;

            if (A[i] == B[i]) cnt = 1;

            if (i > 0) C[i] = C[i-1] + cnt++;
            else C[i] = cnt;
        }

        return C;
    }
};