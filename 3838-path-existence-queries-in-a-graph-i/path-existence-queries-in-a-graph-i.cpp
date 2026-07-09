class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUltiParent(int n) {
        if (parent[n] == n) return n;
        return parent[n] = findUltiParent(parent[n]);
    }

    void unionBySize(int u, int v) {
        int ultiParent_u = findUltiParent(u);
        int ultiParent_v = findUltiParent(v);

        if (ultiParent_u == ultiParent_v) return;
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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet ds(n);

        for (int i = 0; i < n-1; i++) {
            if (abs(nums[i] - nums[i+1]) <= maxDiff) {
                ds.unionBySize(i, i+1);
            }
        }

        vector<bool> ans;
        for (auto q : queries) {
            if (ds.findUltiParent(q[0]) == ds.findUltiParent(q[1])) {
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};