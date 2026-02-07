class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findUltimateParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ultiParent_u = findUltimateParent(u);
        int ultiParent_v = findUltimateParent(v);
        if (ultiParent_u == ultiParent_v) return;
        if (size[ultiParent_u] < size[ultiParent_v]) {
            parent[ultiParent_u] = ultiParent_v;
            size[ultiParent_v] += size[ultiParent_u];
        }
        else {
            parent[ultiParent_v] = ultiParent_u;
            size[ultiParent_u] += size[ultiParent_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for (auto &i : stones) {
            maxRow = max(maxRow, i[0]);
            maxCol = max(maxCol, i[1]);
        }
        int n = maxRow + maxCol + 2;
        DisjointSet ds(n);
        for (auto &i : stones) {
            ds.unionBySize(i[0], i[1] + maxRow + 1);
        }
        int components = 0;
        int nodes = stones.size();
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i && ds.size[i] != 1) components++;
        }
        return nodes - components;
    }
};