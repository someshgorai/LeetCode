class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int res = 1e9;
        int l = 0, sum = 0;
        int bestmin = 1e9;
        vector<int> minLenTill(n, 1e9);

        for (int r = 0; r < n; r++) {
            sum += arr[r];
            while (l <= r && sum > target) {
                sum -= arr[l];
                l++;
            }

            if (sum == target) {
                int len = r - l + 1;
                if (l > 0 && minLenTill[l - 1] != 1e9) {
                    res = min(res, minLenTill[l - 1] + len);
                }
                bestmin = min(bestmin, len);
            }
            minLenTill[r] = bestmin;
        }

        return res == 1e9 ? -1 : res;
    }
};