class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+4, vector<int> (n+4, 0));

        long long total = accumulate(nums.begin(), nums.end(), 0LL);

        for (int left = n-1; left >= 0; left--) {
            for (int right = 0; right < n; right++) {
                if (left > right) continue;
                long long take_left = nums[left] + min(
                    dp[left+4][right+2],
                    dp[left+3][right+1]
                );

                long long take_right = nums[right] + min(
                    dp[left+3][right+1],
                    dp[left+2][right]
                );

                dp[left+2][right+2] = max(take_left, take_right);        
            }
        }

        long long score1 = dp[2][n+1];

        long long score2 = total - score1;

        if (score1 >= score2) {
            return true;
        }

        return false;
    }
};