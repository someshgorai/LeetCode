class Solution {
private:
    int getReverse(int num) {
        int rev = 0;
        while (num > 0) {
            int digit = num % 10;
            rev = rev * 10 + digit;
            num = num / 10;
        }
        return rev;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> reverseIdx;
        int n = nums.size();
        int minAbsDistance = INT_MAX;
        for (int i = 0; i < n; i++) {
            int rev = getReverse(nums[i]);
            if (reverseIdx.count(nums[i]) > 0) {
                minAbsDistance = min(
                    minAbsDistance, 
                    i - reverseIdx[nums[i]]
                );
            }
            reverseIdx[rev] = i;
        }

        if (minAbsDistance == INT_MAX) return -1;
        return minAbsDistance;
    }
};