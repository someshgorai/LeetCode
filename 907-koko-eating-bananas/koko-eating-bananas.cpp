class Solution {
private:
    long long hours(vector<int>& piles, int k) {
        long long hours = 0;
        for (int i=0; i<piles.size(); i++) {
            hours += ceil ((double)piles[i]/ (double)k);
        }
        return hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        
        while (low <= high) {
            long long mid = (high+low)/2;
            long long time = hours(piles, mid);
            if (time <= h) {
                high = mid -1;
            } 
            else {
                low = mid +1;
            }
        }
        return low;
    }
};