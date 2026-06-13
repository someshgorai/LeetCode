class TreeAncestor {
public:
    vector<vector<int>> ancestor;
    TreeAncestor(int n, vector<int>& parent) {
        int row = n, col = log2(n) + 1;
        ancestor.resize(row, vector<int> (col, -1));
        for (int i = 0; i < n; i++) {
            ancestor[i][0] = parent[i];
        }

        for (int j = 1; j < col; j++) {
            for (int node = 0; node < n; node++) {
                if (ancestor[node][j-1] != -1) ancestor[node][j] = ancestor[ancestor[node][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int intermediateParent = node;
        int power = 0;
        while (k) {
            if (k & 1) {
                if (intermediateParent != -1) {
                    intermediateParent = ancestor[intermediateParent][power];
                }
            }
            power++;
            k = k >> 1;
        } 
        return intermediateParent;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */