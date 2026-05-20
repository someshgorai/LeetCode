class Solution {
private:

    int mergeSort(vector<int>& nums, int low, int high, vector<int>& temp) {

        if (low >= high) return 0;

        int mid = low + (high - low) / 2;

        int cnt = 0;

        cnt += mergeSort(nums, low, mid, temp);
        cnt += mergeSort(nums, mid + 1, high, temp);

        // COUNT REVERSE PAIRS
        int right = mid + 1;

        for (int left = low; left <= mid; left++) {

            while (right <= high &&
                   (long long)nums[left] > 2LL * nums[right]) {
                right++;
            }

            cnt += right - (mid + 1);
        }

        // MERGE STEP
        int left = low;
        right = mid + 1;

        int k = low;

        while (left <= mid && right <= high) {

            if (nums[left] <= nums[right]) {
                temp[k++] = nums[left++];
            }
            else {
                temp[k++] = nums[right++];
            }
        }

        while (left <= mid) {
            temp[k++] = nums[left++];
        }

        while (right <= high) {
            temp[k++] = nums[right++];
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i];
        }

        return cnt;
    }

public:
    int reversePairs(vector<int>& nums) {

        int n = nums.size();

        vector<int> temp(n);

        return mergeSort(nums, 0, n - 1, temp);
    }
};