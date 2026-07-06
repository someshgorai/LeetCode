class Solution {
private:
    int helper(vector<int>& nums) {
        int n = nums.size();
        int next_2 = 0, next_1 = 0, curr = 0;

        for (int i = n-1; i >= 0; i--) {
            int pick = nums[i] + next_2;
            int notPick = next_1; 
            curr = max(pick, notPick);
            next_2 = next_1;
            next_1 = curr;
        }
        return curr;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                temp1.push_back(nums[i]);
                continue;
            }
            if (i == n-1) {
                temp2.push_back(nums[i]);
                continue;
            }
            temp1.push_back(nums[i]);
            temp2.push_back(nums[i]);
        }
        return max(helper(temp1), helper(temp2));
    }
};