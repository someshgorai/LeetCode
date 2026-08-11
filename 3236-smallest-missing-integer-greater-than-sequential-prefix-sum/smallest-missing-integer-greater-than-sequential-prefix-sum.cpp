class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int prefixSum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1] + 1) {
                prefixSum += nums[i];
            }
            else break;
        }

        unordered_set<int> s;
        for (int i : nums) {
            s.insert(i);
        }

        while(s.find(prefixSum) != s.end()) {
            prefixSum++;
        }

        return prefixSum;
    }
};