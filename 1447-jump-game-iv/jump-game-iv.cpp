class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i < n; i++) {
            mpp[arr[i]].push_back(i);
        }

        queue<pair<int,int>> q; // node, jumps
        vector<bool> visited(n, false);
        q.emplace(n-1, 0);
        visited[n-1] = true;

        while(!q.empty()) {
            auto [idx, jumps] = q.front();
            if (idx == 0) return jumps;
            q.pop();

            if (idx + 1 < n && visited[idx+1] == false) {
                q.emplace(idx + 1, jumps + 1);
                visited[idx+1] = true;
            }

            if (idx - 1 >= 0 && visited[idx-1] == false) {
                q.emplace(idx - 1, jumps + 1);
                visited[idx-1] = true;
            }

            for (int i : mpp[arr[idx]]) {
                if (i == idx) continue;
                if (visited[i] == false) {
                    q.emplace(i, jumps+1);
                    visited[i] = true;
                }
            }
            mpp[arr[idx]].clear();
        }

        return 1;
    }
};