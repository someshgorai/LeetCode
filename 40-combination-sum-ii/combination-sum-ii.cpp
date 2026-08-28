class Solution {
private:   
    void backtrack(int idx, int n, int target, vector<int> &comb, vector<vector<int>> &ans, vector<int> &candidates) {
        if (idx == n) {
            if (target == 0) ans.push_back(comb);
            return;
        }

        if (candidates[idx] <= target) {
            comb.push_back(candidates[idx]);
            backtrack(idx+1, n, target - candidates[idx], comb, ans, candidates);
            comb.pop_back();
        }

        int it = idx;
        while (it < n && candidates[idx] == candidates[it]) it++;
        backtrack(it, n, target, comb, ans, candidates);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        backtrack(0, n, target, comb, ans, candidates);
        return ans;
    }
};