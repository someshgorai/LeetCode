class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        vector<int> cubes;
        for (int i = 0; i * i * i <= n; i++) {
            cubes.push_back(i * i * i);
        }

        int m = cubes.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < m; i++) {
            int j = i;
            while (j < m) {
                int sum = cubes[i] + cubes[j];
                if (sum > n) break;
                mp[sum]++;
                j++;
            }
        }

        vector<int> ans;
        for (auto &it : mp) {
            if (it.second >= 2) {
                ans.push_back(it.first);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};