class DisjointSet {
public:
    vector<int> size, parent;
    DisjointSet (int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUltiParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUltiParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ultiParent_u = findUltiParent(u);
        int ultiParent_v = findUltiParent(v);
        if (size[ultiParent_u] >= size[ultiParent_v]) {
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // Need to create MST
        int n = edges.size();
        DisjointSet ds(n + 1);
        vector<int> extraEdge;
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (ds.findUltiParent(u) != ds.findUltiParent(v)) {
                ds.unionBySize(u, v);
            }
            else {
                extraEdge = edge;
            }
        }

        return extraEdge;
    }
};