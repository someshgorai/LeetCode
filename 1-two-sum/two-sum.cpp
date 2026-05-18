class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            int rem = target - nums[i];
            
            if (mpp.count(rem)) {
                for (int j : mpp[rem]) {
                    if (i != j) return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};