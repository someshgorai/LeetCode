class Solution {
private:
    pair<int, int> getLargestPair(vector<int>& nums) {
        int n = nums.size();

        int large = 0, secLarge = 1;

        if (nums[secLarge] > nums[large])
            swap(large, secLarge);

        for (int i = 2; i < n; i++) {
            if (nums[i] > nums[large]) {
                secLarge = large;
                large = i;
            }
            else if (nums[i] > nums[secLarge]) {
                secLarge = i;
            }
        }

        return {large, secLarge};
    }

public:
    int lastStoneWeight(vector<int>& stones) {
        vector<int> nums = stones;

        while (nums.size() > 1) {
            auto [largest, secLargest] = getLargestPair(nums);

            nums[largest] -= nums[secLargest];

            if (nums[largest] == 0) {
                if (largest > secLargest) {
                    nums.erase(nums.begin() + largest);
                    nums.erase(nums.begin() + secLargest);
                }
                else {
                    nums.erase(nums.begin() + secLargest);
                    nums.erase(nums.begin() + largest);
                }
            }
            else {
                nums.erase(nums.begin() + secLargest);
            }
        }

        return nums.empty() ? 0 : nums[0];
    }
};