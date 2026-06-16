class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 1; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUltiParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUltiParent(parent[node]);
    }

    bool unionBySize(int u, int v) {
        int ultiParent_u = findUltiParent(u);
        int ultiParent_v = findUltiParent(v);
        if (ultiParent_u == ultiParent_v) return false;
        if (size[ultiParent_u] >= size[ultiParent_v]) {
            parent[ultiParent_v] = ultiParent_u;
            size[ultiParent_u] += size[ultiParent_v];
        }
        else {
            parent[ultiParent_u] = ultiParent_v;
            size[ultiParent_v] += size[ultiParent_u];
        }
        return true;
    }   
};
class Solution {
public:
    vector<int> detectCycle(int n, vector<vector<int>> &edges, vector<int> skipEdge) {
        DisjointSet ds(n+1);
        for (vector<int> edge : edges) {
            if (edge == skipEdge) continue;
            if (!ds.unionBySize(edge[0], edge[1])) return edge;
        }
        return {};
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n+1);
        vector<int> indegree(n+1, 0);
        int hasTwoIndegree = -1;
        for (auto edge : edges) {
            indegree[edge[1]]++;
            if (indegree[edge[1]] == 2) hasTwoIndegree = edge[1];
        }

        if (hasTwoIndegree == -1) return detectCycle(n, edges, {});

        vector<int> extraEdge;
        for (auto skipEdge : edges) {
            if (skipEdge[1] == hasTwoIndegree) {
                if (detectCycle(n, edges, skipEdge).empty()) extraEdge = skipEdge;
            }
        }
        return extraEdge;
    }
};