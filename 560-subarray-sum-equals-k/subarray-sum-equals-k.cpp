class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map<int, int> mpp;
        mpp[0]++;

        for (int i : nums) {
            sum += i;

            int extra = sum - k;
            if (mpp.find(extra) != mpp.end()) {
                count += mpp[extra];
            }

            mpp[sum]++;
        }
        return count;
    }
};