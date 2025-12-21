class Solution {
private:
    bool isPossible(vector<int>& bloomDay, int m , int k, int day) {
        int n = bloomDay.size(), count = 0, bouquets = 0;
        for (int i : bloomDay) {
            if (i<=day) {
                count++;
                if (count == k) {
                    if (++bouquets == m) return true;
                    count = 0;
                }
            }
            else {
                count  = 0;
            }
        }
        return bouquets >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (1LL * m * k > 1LL * n) return -1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(bloomDay, m, k, mid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
            
        }
        return low;
    }
};