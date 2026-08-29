class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end());

        vector<int> grpVal;
        vector<int> grpIdx;
        vector<vector<int>> grps;
        vector<vector<int>> idxs;

        grpVal.push_back(temp[0].first);
        grpIdx.push_back(temp[0].second);

        for (int i = 1; i < n; i++) {
            auto it1 = temp[i-1];
            auto it2 = temp[i];

            if (it2.first - it1.first <= limit) {
                grpVal.push_back(it2.first);
                grpIdx.push_back(it2.second);
            }
            else {
                sort(grpVal.begin(), grpVal.end());
                sort(grpIdx.begin(), grpIdx.end());

                grps.push_back(grpVal);
                idxs.push_back(grpIdx);

                grpVal.clear();
                grpIdx.clear();

                grpVal.push_back(it2.first);
                grpIdx.push_back(it2.second);
            }
        }

        if (!grpVal.empty()) {
            sort(grpVal.begin(), grpVal.end());
            sort(grpIdx.begin(), grpIdx.end());

            grps.push_back(grpVal);
            idxs.push_back(grpIdx);
        }

        vector<int> ans(n);
        int m = grps.size();
        for (int i = 0; i < m; i++) {
            auto grp = grps[i];
            auto idx = idxs[i];

            for (int j = 0; j < grp.size(); j++) {
                ans[idx[j]] = grp[j];
            }
        }

        return ans;
    }
};