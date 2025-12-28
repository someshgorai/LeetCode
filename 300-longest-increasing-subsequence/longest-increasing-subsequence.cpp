class Solution {
private:
    void placeNum(vector<int> &nums, int k) {
        int low = 0, high = nums.size()-1;
        while (low <= high) {
            int mid = (high-low)/2 + low;
            if (nums[mid] == k) return;
            if (nums[mid] > k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        nums[low] = k;
        return;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLen = 1;
        vector<int> seq;
        seq.push_back(nums[0]);
        for (int i=1; i<n; i++) {
            if (nums[i] > seq.back()) {
                seq.push_back(nums[i]);
                maxLen++;
            }
            else {
                placeNum(seq, nums[i]);
            }
        }
        return maxLen;
    }
};