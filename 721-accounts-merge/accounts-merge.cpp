class DisjointSet {
public:
    vector<int> parent;

    DisjointSet(int n) : parent(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) parent[y] = x;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> emailOwner;
        emailOwner.reserve(100000);      // avoid rehashing

        // 1. Union by shared emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                const string& email = accounts[i][j];
                if (!emailOwner.count(email))
                    emailOwner[email] = i;
                else
                    ds.unite(i, emailOwner[email]);
            }
        }

        // 2. Group emails by parent
        unordered_map<int, vector<string>> groups;
        groups.reserve(n);

        for (auto &p : emailOwner) {
            int root = ds.find(p.second);
            groups[root].push_back(p.first);
        }

        // 3. Build result
        vector<vector<string>> res;
        res.reserve(groups.size());

        for (auto &g : groups) {
            auto &emails = g.second;
            sort(emails.begin(), emails.end());

            vector<string> account;
            account.reserve(emails.size() + 1);
            account.push_back(accounts[g.first][0]); // name
            for (auto &e : emails) account.push_back(e);

            res.push_back(move(account));
        }

        return res;
    }
};
