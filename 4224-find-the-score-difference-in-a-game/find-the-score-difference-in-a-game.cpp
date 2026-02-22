class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0, p2 = 0, alter = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1) {
                swap(p1, p2);
                alter++;
            }
            if ((i + 1) % 6 == 0) {
                swap(p1, p2);
                alter++;
            }
            p1 += nums[i];
        }
        if (alter & 1) return p2 - p1;
        return p1 - p2;
    }
};