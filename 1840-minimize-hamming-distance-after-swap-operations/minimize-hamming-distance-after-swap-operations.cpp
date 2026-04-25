class DisjointSet {
public:
    vector<int> size;
    vector<int> parent;
    DisjointSet(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int child) {
        if (child == parent[child]) return child;
        return findParent(parent[child]);
    }

    void unionBySize(int u, int v) {
        int ultiParent_u = findParent(u);
        int ultiParent_v = findParent(v);
        if (ultiParent_u == ultiParent_v) return;
        if (size[ultiParent_u] < size[ultiParent_v]) {
            parent[ultiParent_u] = ultiParent_v;
            size[ultiParent_v] += ultiParent_u;
        }
        else {  
            parent[ultiParent_v] = ultiParent_u;
            size[ultiParent_u] += ultiParent_v;
        }
    }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = target.size();

        DisjointSet ds(n);
        for (auto s : allowedSwaps) {
            ds.unionBySize(s[0], s[1]);
        }

        unordered_map<int, unordered_map<int, int>> groupFreq;

        for (int i = 0; i < n; i++) {
            int parent = ds.findParent(i);
            groupFreq[parent][source[i]]++;
        }

        int hammingDist = 0;
        for (int i = 0; i < n; i++) {
            int parent = ds.findParent(i);
            if (groupFreq[parent][target[i]] > 0) {
                groupFreq[parent][target[i]]--;
            }
            else {
                hammingDist++;
            }
        }

        return hammingDist;
    }
};