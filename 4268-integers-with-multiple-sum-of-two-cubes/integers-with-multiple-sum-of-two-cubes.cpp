class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> mp;
        vector<int> ans;
        int limit = cbrt(n);

        for (int i = 0; i <= limit; i++) {
            int i_3 = i * i * i;
            for (int j = i; j <= limit; j++) {
                int j_3 = j * j * j;
                int sum = i_3 + j_3;
                if (sum > n) break;
                mp[sum]++;
            }
        }
        for (auto &it : mp) {
            if (it.second >= 2) ans.push_back(it.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};