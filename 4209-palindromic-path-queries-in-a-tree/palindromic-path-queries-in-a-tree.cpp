class Solution {
private:
    vector<vector<int>> tree;
    vector<int> entryTime;
    vector<int> exitTime;
    vector<vector<int>> ancestors;
    vector<int> fenwickTree;
    string currentString;
    int currentTime;
    int numNodes;
    const int MAX_LOG = 20;

    void preprocessTree(int node, int parent) {
        entryTime[node] = ++currentTime;
        
        ancestors[node][0] = parent;
        for (int i = 1; i < MAX_LOG; ++i) {
            ancestors[node][i] = ancestors[ancestors[node][i - 1]][i - 1];
        }

        for (int neighbor : tree[node]) {
            if (neighbor != parent) {
                preprocessTree(neighbor, node);
            }
        }
        
        exitTime[node] = currentTime;
    }

    bool isAncestor(int u, int v) {
        return entryTime[u] <= entryTime[v] && exitTime[u] >= exitTime[v];
    }

    int findLCA(int u, int v) {
        if (isAncestor(u, v)) return u;
        if (isAncestor(v, u)) return v;

        for (int i = MAX_LOG - 1; i >= 0; --i) {
            if (!isAncestor(ancestors[u][i], v)) {
                u = ancestors[u][i];
            }
        }
        return ancestors[u][0];
    }

    void updateBIT(int index, int val) {
        while (index <= numNodes) {
            fenwickTree[index] ^= val;
            index += index & -index;
        }
    }

    void updateSubtree(int u, int val) {
        updateBIT(entryTime[u], val);
        updateBIT(exitTime[u] + 1, val);
    }

    int queryBIT(int index) {
        int result = 0;
        while (index > 0) {
            result ^= fenwickTree[index];
            index -= index & -index;
        }
        return result;
    }

    int getCharMask(char c) {
        return 1 << (c - 'a');
    }

    bool canFormPalindrome(int mask) {
        return mask == 0 || (mask & (mask - 1)) == 0;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->numNodes = n;
        this->currentString = s;
        
        tree.assign(n, vector<int>());
        for (const auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        entryTime.assign(n, 0);
        exitTime.assign(n, 0);
        ancestors.assign(n, vector<int>(MAX_LOG));
        currentTime = 0;

        preprocessTree(0, 0);

        fenwickTree.assign(n + 2, 0);
        for (int i = 0; i < n; ++i) {
            updateSubtree(i, getCharMask(s[i]));
        }

        vector<bool> results;

        for (const string& query : queries) {
            int firstSpace = query.find(' ');
            int secondSpace = query.rfind(' ');
            
            if (query[0] == 'u') {
                int u = stoi(query.substr(firstSpace + 1, secondSpace - firstSpace - 1));
                char newChar = query.back();

                int oldMask = getCharMask(currentString[u]);
                int newMask = getCharMask(newChar);
                int xorDiff = oldMask ^ newMask;

                currentString[u] = newChar;
                updateSubtree(u, xorDiff);
            } else {
                int u = stoi(query.substr(firstSpace + 1, secondSpace - firstSpace - 1));
                int v = stoi(query.substr(secondSpace + 1));

                int lcaNode = findLCA(u, v);
                
                int pathMask = queryBIT(entryTime[u]) ^ 
                               queryBIT(entryTime[v]) ^ 
                               getCharMask(currentString[lcaNode]);

                results.push_back(canFormPalindrome(pathMask));
            }
        }

        return results;
    }
};