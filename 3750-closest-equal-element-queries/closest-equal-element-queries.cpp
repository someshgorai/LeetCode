class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> numIndices;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            numIndices[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int &q : queries) {
            vector<int> &vec = numIndices[nums[q]];
            int m = vec.size();
 
            if (m == 1) {
                ans.push_back(-1);
                continue;
            }

            int startIdx = lower_bound(vec.begin(), vec.end(), q) - vec.begin();

            int minDistance = INT_MAX;

            int leftIdx = vec[(startIdx - 1 + m) % m];
            minDistance = min(minDistance, min(abs(q - leftIdx), n - abs(q - leftIdx)));

            int rightIdx = vec[(startIdx + 1) % m];
            minDistance = min(minDistance, min(abs(q - rightIdx), n - abs(q - rightIdx)));

            ans.push_back(minDistance);
        }

        return ans;
    }
};