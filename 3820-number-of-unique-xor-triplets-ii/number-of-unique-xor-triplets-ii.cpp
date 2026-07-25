class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = 1;
        int m = *max_element(nums.begin(), nums.end());
        while (m >= n) {
            n = n << 1;
        }
        
        int k = nums.size();
        vector<bool> s1(n, false);
        vector<bool> s2(n, false);
        for (int i = 0; i < k; i++) {
            for (int j = i; j < k; j++) {
                s1[nums[i] ^ nums[j]] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (s1[i]) {
                for (int &j : nums) {
                    s2[i ^ j] = true;
                }
            }
        }

        int cnt = 0;
        for (bool i : s2) {
            if (i) cnt++;
        }
        return cnt;
    }
};