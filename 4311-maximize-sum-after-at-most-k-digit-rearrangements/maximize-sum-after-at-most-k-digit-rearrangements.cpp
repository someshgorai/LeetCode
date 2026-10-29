class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        vector<int> gain(n, 0);
        for (int i = 0; i < n; i++) {
            string num = to_string(nums[i]);
            sort(num.begin(), num.end(), greater<char>());
            int newNum = stoi(num);
            gain[i] = newNum - nums[i];
            sum += nums[i];
        }
        sort(gain.begin(), gain.end(), greater<>());
        for (int i = 0; i < k; i++) {
            sum += gain[i];
        }

        return sum;
    }
};