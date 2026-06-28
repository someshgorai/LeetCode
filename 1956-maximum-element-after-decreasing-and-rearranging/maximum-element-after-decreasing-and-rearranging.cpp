class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<int> res(n, 1);
        for (int i = 1; i < n; i++) {
            if (arr[i] == res[i-1]) res[i] = arr[i];
            else {
                res[i] = res[i-1] + 1;
            }
        }
        return res[n-1];
    }
};