class Solution {
private:
    bool check(long long num, int x) {
        if (num % 10 != x) return false;
        while (num >= 10) num/=10;
        
        return num == x;
    }
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (check(sum, x)) count++;
            }
        }
        return count;
    }
};