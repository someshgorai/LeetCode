class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        map<int, int> freq;
        for (int i: nums) {
            freq[i]++;
        }
        for (auto &i : freq) {
            if (i.second == n) return i.first;
        }
        return -1;
    }
};