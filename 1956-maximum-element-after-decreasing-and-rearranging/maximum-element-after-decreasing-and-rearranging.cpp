class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int prev = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == prev) prev = arr[i];
            else {
                prev = prev + 1;
            }
        }
        return prev;
    }
};