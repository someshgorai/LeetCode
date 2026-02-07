class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet (int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUltimateParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize (int u, int v) {
        int ultiParent_u = parent[u];
        int ultiParent_v = parent[v];
        if (ultiParent_u == ultiParent_v) return;
        if (size[ultiParent_u] > size[ultiParent_v]) {
            parent[ultiParent_v] = ultiParent_u;
            size[ultiParent_u] += size[ultiParent_v];
        }
        else {
            parent[ultiParent_u] = ultiParent_v;
            size[ultiParent_v] += size[ultiParent_u];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra = 0;
        for (auto &i : connections) {
            if (ds.findUltimateParent(i[0]) == ds.findUltimateParent(i[1])) extra++;
            else ds.unionBySize(i[0], i[1]);
        }
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) components++;
        }
        if (extra >= components - 1) return components - 1;
        return -1;
    }
};