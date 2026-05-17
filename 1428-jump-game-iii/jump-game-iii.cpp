class Solution {
private:
    bool backtrack(vector<int>& arr, vector<bool>& vis, int idx, int n) {
        // Base Case
        if (vis[idx]) return false;
        if (arr[idx] == 0) return true;

        vis[idx] = true;

        bool res = false;

        if (idx + arr[idx] < n) res = backtrack(arr, vis, idx + arr[idx], n);
        if (idx - arr[idx] >= 0) res = res || backtrack(arr, vis, idx - arr[idx], n);

        return res;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);

        return backtrack(arr, vis, start, n);
    }
};