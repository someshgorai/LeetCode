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
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        DisjointSet ds(n * m);
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 0) continue;
                int node1 = i * m + j;
                for (int k=0; k<4; k++) {
                    int r = i + drow[k];
                    int c = j + dcol[k];
                    if (r < 0 || r >= n || c < 0 || c >= m) continue;
                    if (grid[r][c] == 1) {
                        int node2 = r * m + c;
                        ds.unionBySize(node1, node2);
                    }
                }
            }
        }

        int maxArea = 0;
        bool allone = true;
        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    allone = false;
                    int node1 = i * m + j;
                    for (int k=0; k<4; k++) {
                        int r = i + drow[k];
                        int c = j + dcol[k];
                        if (r < 0 || r >= n || c < 0 || c >= m) continue;
                        if (grid[r][c] == 1) {
                            int node2 = r * m + c;
                            st.insert(ds.findUltiParent(node2));
                        }
                    }
                    int area = 0;
                    while (!st.empty()) {
                        area += ds.size[*st.begin()];
                        st.erase(*st.begin());
                    }
                    maxArea = max(maxArea, area + 1);
                }
            }
        }
        if (allone) return n * m;
        return maxArea;
    }
};