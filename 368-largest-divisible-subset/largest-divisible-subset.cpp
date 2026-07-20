class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n, 1);
        vector<int> prev(n);
        int maxIdx = 0;
        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++) {
            prev[i] = i;
            for (int j = 0; j < i; j++) {
                if ((nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) && len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;
                    prev[i] = j;
                    if (len[maxIdx] < len[i]) maxIdx = i;
                }
            }
        }

        vector<int> ans(len[maxIdx]);
        int lastIdx = maxIdx;
        int idx = len[maxIdx]-1;
        while (prev[lastIdx] != lastIdx) {
            ans[idx] = nums[lastIdx];
            lastIdx = prev[lastIdx];
            idx--;
        }
        ans[0] = nums[lastIdx];
        return ans;
    }
};