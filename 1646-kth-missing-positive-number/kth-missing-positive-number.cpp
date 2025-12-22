class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int high = *max_element(arr.begin(), arr.end()); //O(N)
        int miss = 0, j = 0;
        for (int i=1; i<=high; i++) {
            if (arr[j] != i) {
                miss++;
                if (miss == k) return i;
            }
            else{
                j++;
            }
        }
        return high - miss + k;
    }
};