class Solution {
private:
    unordered_set<int> getEdges(vector<int> &fences, int border) {
        unordered_set<int> st;
        fences.push_back(1);
        fences.push_back(border);
        int n = fences.size();
        sort(fences.begin(), fences.end());
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                st.insert(fences[j] - fences[i]);
            }
        }
        return st;
    }
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int> hEdges = getEdges(hFences, m);
        unordered_set<int> vEdges = getEdges(vFences, n);
        int res = 0, mod = 1e9 + 7;
        for (int e : hEdges) {
            if (vEdges.count(e)) {
                res = max(res, e);
            }
        }
        if (res == 0) {
            res = -1;
        }
        else {
            res = 1LL * res * res % mod;
        }
        return res;
    }
};