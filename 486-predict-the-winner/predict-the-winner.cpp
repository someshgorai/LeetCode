class Solution {
private:
    long long backtrack(vector<int> &nums, int left, int right) {
        if (left > right) {
            return 0;
        }

        long long take_left = nums[left] + min(
            backtrack(nums, left+2, right),
            backtrack(nums, left+1, right-1)
        );

        long long take_right = nums[right] + min(
            backtrack(nums, left+1, right-1),
            backtrack(nums, left, right-2)
        );

        return max(take_left, take_right);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);

        long long score1 = backtrack(nums, 0, n-1);

        long long score2 = total - score1;

        if (score1 >= score2) {
            return true;
        }

        return false;
    }
};