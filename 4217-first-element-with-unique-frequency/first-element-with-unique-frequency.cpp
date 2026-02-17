class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counts, vis;
        for (int i : nums) {
            vis[i]++;
        }
        for (auto &i : vis) {
            counts[i.second]++;
        }
        for (int i = 0; i < n; i++) {
            if (counts[vis[nums[i]]] == 1) return nums[i];
        }
        return -1;
    }
};