class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        vector<int> res(n, -1);

        int l = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            if (r-l+1 == 2*k+1) {
                int center = r - k;
                res[center] = sum/ ((1LL) * (2*k+1));
                sum -= nums[l];
                l++;
            }
        }
        return res;
    }
};