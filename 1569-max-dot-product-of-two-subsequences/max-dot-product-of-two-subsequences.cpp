class Solution {
private:
    int backtrack(int idx1, int idx2, vector<int>& nums1, vector<int>& nums2, int s1, int s2, vector<vector<int>> &dp) {
        // Base Case
        if (idx1 == s1 || idx2 == s2) return INT_MIN;

        if (dp[idx1][idx2] != INT_MIN) return dp[idx1][idx2];

        // one each
        int take = nums1[idx1] * nums2[idx2];
        int next =  backtrack(idx1+1, idx2+1, nums1, nums2, s1, s2, dp);
        if (next != INT_MIN) take = max(take, take+next);
        // skip nums1
        int skip1 = backtrack(idx1+1, idx2, nums1, nums2, s1, s2, dp);
        // skip nums2
        int skip2 = backtrack(idx1, idx2+1, nums1, nums2, s1, s2, dp);

        return dp[idx1][idx2] = max({take, skip1, skip2});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size();
        vector<vector<int>> dp(2, vector<int> (s2+1, INT_MIN));
        for (int idx1=s1-1; idx1>=0; idx1--) {
            for (int idx2=s2-1; idx2>=0; idx2--) {
                // one each
                int take = nums1[idx1] * nums2[idx2];
                int next =  dp[1][idx2+1];
                if (next != INT_MIN) take = max(take, take+next);
                // skip nums1
                int skip1 = dp[1][idx2];
                // skip nums2
                int skip2 = dp[0][idx2+1];

                dp[0][idx2] = max({take, skip1, skip2});
            }
            dp[1] = dp[0];
        }
        return dp[0][0];
    }
};