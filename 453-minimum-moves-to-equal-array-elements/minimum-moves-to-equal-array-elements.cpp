class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minEle = *min_element(nums.begin(), nums.end());
        int steps = 0;
        for (int i : nums) {
            steps += i - minEle;
        }

        return steps;
    }
};