class Solution {
private:  
    long long mod = 1e9 + 7;
    vector<vector<long long>> nCr;
    int getWays(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1) return 1;

        vector<int> leftTree, rightTree; 
        for (int i = 1; i < n; i++) {
            if (nums[0] < nums[i]) {
                rightTree.push_back(nums[i]);
            }
            else {
                leftTree.push_back(nums[i]);
            }
        }

        long long leftWays  = getWays(leftTree);
        long long rightWays = getWays(rightTree);
        long long currWays  = nCr[n-1][leftTree.size()];

        return (int)(((leftWays * rightWays) % mod) * currWays % mod);
    }
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        nCr.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            nCr[i][0] = nCr[i][i] = 1;
            for (int j = 1; j < i; j++) {
                nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % mod;
            }
        }
        return getWays(nums) - 1;
    }
};