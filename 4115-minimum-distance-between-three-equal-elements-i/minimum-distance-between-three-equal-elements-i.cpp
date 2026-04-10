class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> indices;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            indices[nums[i]].push_back(i);
        }

        int minDist = 1e9;
        for (auto &[k, pos] : indices) {
            int m = pos.size();
            // cout << m;
            if (m >= 3) {
                for (int i = 0; i < m - 2; i++) {
                    minDist = min(minDist, 2 * (pos[i+2] - pos[i]));
                }
            }
        }
        
        if (minDist == 1e9) return -1;
        return minDist;
    }
};