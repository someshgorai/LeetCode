class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
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

    int getScore(vector<int> cityScore) {
        int ultiParent_1 = findUltiParent(1);
        int minScore = cityScore[1];
        int n = cityScore.size();

        for (int i = 2; i < n; i++) {
            if (findUltiParent(i) == ultiParent_1) {
                minScore = min(minScore, cityScore[i]);
            }
        }

        return minScore;
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet ds(n+1);
        vector<int> cityScore(n+1, 1e9);
        for (auto road : roads) {
            ds.unionBySize(road[0], road[1]);
            cityScore[road[0]] = min(cityScore[road[0]], road[2]);
            cityScore[road[1]] = min(cityScore[road[1]], road[2]);
        }

        return ds.getScore(cityScore);
    }
};