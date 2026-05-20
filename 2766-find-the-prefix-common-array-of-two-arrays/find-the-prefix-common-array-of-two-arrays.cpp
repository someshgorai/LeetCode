class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int> setA, setB;
        vector<int> C(n);

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            setA.insert(A[i]);
            setB.insert(B[i]);

            if (A[i] == B[i]) cnt = 1;

            else {
                // For A
                if (setB.find(A[i]) != setB.end()) {
                    cnt++;
                }

                // For B
                if (setA.find(B[i]) != setA.end()) {
                    cnt++;
                }
            }


            if (i > 0) C[i] = C[i-1] + cnt;
            else C[i] = cnt;
        }
        return C;
    }
};