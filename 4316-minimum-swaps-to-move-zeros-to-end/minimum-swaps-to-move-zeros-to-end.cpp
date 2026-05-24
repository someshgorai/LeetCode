class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) pos.push_back(i);
        }
        int p = pos.size(), ops = 0;
        for (int i = 0; i < p; i++) {
            if (pos[i] < (n - p)) {
                ops++;
            }
            else break;
        }
        return ops;
    }
};