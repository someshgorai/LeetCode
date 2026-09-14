class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int mod = sum % k;
            if (mod < 0) mod = mod + k;
            if (mp.find(mod) != mp.end()) {
                cnt += mp[mod];
            }
            mp[mod]++;
        }

        return cnt;
    }
};