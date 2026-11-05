class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // sort(arr1.begin(), arr1.end());
        // sort(arr2.begin(), arr2.end());
        int n = arr1.size(), m = arr2.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            bool isValid = true;
            for (int j = 0; j < m; j++) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) cnt++;
        }

        return cnt;
    }
};