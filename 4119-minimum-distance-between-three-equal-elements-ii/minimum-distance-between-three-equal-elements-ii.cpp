class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, pair<int,int>> lastTwo; 
        // {prev2, prev1}

        int minDist = 1e9;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if (lastTwo.count(x)) {
                auto &[prev2, prev1] = lastTwo[x];

                if (prev2 != -1) {
                    minDist = min(minDist, 2 * (i - prev2));
                }

                // shift
                prev2 = prev1;
                prev1 = i;
            } else {
                lastTwo[x] = {-1, i};
            }
        }

        return (minDist == 1e9) ? -1 : minDist;
    }
};