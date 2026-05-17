class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n);

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int idx = q.front();
            q.pop();

            if (idx < 0 || idx >= n || vis[idx]) continue;

            if (arr[idx] == 0) return true;
            vis[idx] = true;
            q.push(idx + arr[idx]);
            q.push(idx - arr[idx]); 
        }

        return false;
    }
};