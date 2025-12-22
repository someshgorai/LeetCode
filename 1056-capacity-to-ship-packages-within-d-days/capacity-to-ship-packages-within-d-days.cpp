class Solution {
private:
    bool isValid(vector<int>& weights, int capacity, int limit) {
        int load = 0;
        int days = 1;
        for (int i=0; i<weights.size(); i++) {
            if (load + weights[i] > capacity) {
                load = weights[i];
                days++;
                if (days > limit) return false;
            }
            else {
                load += weights[i];
            }
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long low = *max_element(weights.begin(), weights.end());
        long long high = accumulate(weights.begin(), weights.end(), 0LL);
        while (low <= high) {
            long long mid = (low+high)/2;
            if (isValid(weights, mid, days)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};