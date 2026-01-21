class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int i : nums) {
            if (i == 2) {
                ans.push_back(-1);
                continue;
            }
            int prev;
            for (int j=0; j<32; j++) {
                if ((i & (1 << j)) != 0) continue;
                prev = j-1;
                break;
            }
            ans.push_back(i ^ (1 << prev));
        }

        return ans;
    }
};
