class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> groups(n, 0);
        int groupsCnt = 0;

        for (int i = 0; i < n-1; i++) {
            if (abs(nums[i] - nums[i+1]) <= maxDiff) {
                groups[i+1] = groupsCnt;
            }
            else {
                groupsCnt++;
                groups[i+1] = groupsCnt;
            }
        }

        vector<bool> ans;
        for (auto q : queries) {
            if (groups[q[0]] == groups[q[1]]) {
                ans.push_back(true);
            }
            else ans.push_back(false);
        }

        return ans;
    }
};