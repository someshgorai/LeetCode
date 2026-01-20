class Solution {
private:
    int bit (int n) {
        for (int i=0; i<n; i++){
            if ((i | (i+1)) == n) return i;
        }
        return -1;
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n =nums.size();
        vector<int> ans(n);
        for (int i=0; i<n; i++) {
            ans[i] = bit(nums[i]);
        }
        return ans;
    }
};