class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUltiParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUltiParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int up_u = findUltiParent(u);
        int up_v = findUltiParent(v);

        if (up_u == up_v) return;

        if (size[up_u] < size[up_v]) {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        } else {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};
class Solution {
private:
    bool isValid(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int drow[4] = {0, 1, 0, -1};
        int dcol[4] = {1, 0, -1, 0};
        set<pair<int, pair<int, int>>> queries;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                queries.insert({grid[i][j], {i, j}});
            }
        }

        DisjointSet ds(n * n);

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for (auto it = queries.begin(); it != queries.end(); ++it) {
            int time = it->first;
            int x = it->second.first;
            int y = it->second.second;
            int node1 = n * x + y;
            vis[x][y] = true;
            for (int i = 0; i<4
            ; i++) {
                int nrow = x + drow[i];
                int ncol = y + dcol[i];
                if (isValid(nrow, ncol, n) && vis[nrow][ncol]) {
                    int node2 = nrow * n + ncol;
                    ds.unionBySize(node1, node2);
                }
            }
            if (ds.findUltiParent(0) == ds.findUltiParent(n*n - 1)) return time;

        }
        return -1;
    }
};