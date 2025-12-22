class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int high = *max_element(arr.begin(), arr.end()); //O(N)
        vector<bool> missing(high+1, true);
        int miss = 0;
        for (int i:arr) { // alternative : take all numbers
            missing[i] = false;
        }
        for (int i=1; i<=high; i++) {
            if (missing[i]) {
                miss++;
                if (miss == k) return i;
            }
        }
        return (high - miss) + k;
    }
};