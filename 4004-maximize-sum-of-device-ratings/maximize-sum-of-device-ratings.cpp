class Solution {
public:
int secondMax(vector<int>& nums, int& x){
    if (nums.size() < 2) {
        x = min(x, nums[0]);
        return nums[0];  
    }
    int mini = INT_MAX;
    int mini2 = INT_MAX;
    int n = nums.size();
    
    for(int i=0; i<n; i++){
        if(nums[i] < mini){
            mini2 = mini;
            mini = nums[i];
            continue;
        }
        if(nums[i] < mini2){
            mini2 = nums[i];
        }
    }
    x = min(x, mini);
    return mini2;
}
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        long long ans = 0;
        int x = INT_MAX;
        int small = INT_MAX;
        for(int i=0; i<m; i++){
            int num = secondMax(units[i], x);
            if(num < small){
                small = num;
            }
            ans += num;
        }
        ans -= small;
        ans += x;
        return ans;
    }
};