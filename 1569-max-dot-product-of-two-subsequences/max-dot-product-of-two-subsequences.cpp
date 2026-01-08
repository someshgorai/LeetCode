class Solution {
private:
    int backtrack(int idx1, int idx2, vector<int>& nums1, vector<int>& nums2, int s1, int s2, bool taken, vector<vector<int>> &dp) {
        // Base Case
        if (idx1 == s1 || idx2 == s2) {
            if (taken) return 0;
            else return INT_MIN;
        }

        if (dp[idx1][idx2] != INT_MIN) return dp[idx1][idx2];

        int take = INT_MIN;
        for (int i=idx2; i<s2; i++) {
            take = max(nums1[idx1] * nums2[i] + backtrack(idx1+1, i+1, nums1, nums2, s1, s2, true, dp), take);
        }
        
        return dp[idx1][idx2] = max(take, backtrack(idx1+1, idx2, nums1, nums2, s1, s2, taken, dp));
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size();
        vector<vector<int>> dp(s1, vector<int> (s2, INT_MIN));
        return backtrack(0, 0, nums1, nums2, nums1.size(), nums2.size(), false, dp);
    }
};