class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        vector<vector<int>> freq(n+1);
        for (auto &[num, count] : mp) {
            freq[count].push_back(num);
        }

        vector<int> res;
        for (int i = n; i >= 1 && k > 0; i--) {
            int len = freq[i].size();
            int cnt = 0;

            if (len > 0) {   
                for (int j = 0; j <= min(k, len-1); j++) {
                    res.push_back(freq[i][j]);
                    cnt++;
                }
            }

            k -= cnt;
        }

        return res;
    }
};