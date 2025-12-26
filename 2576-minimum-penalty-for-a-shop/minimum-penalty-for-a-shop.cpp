class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
        for (char i:customers) {
            if (i == 'Y') penalty++;
        }
        if (penalty == 0) return 0;
        int minPenalty = penalty, n = customers.size(), idx = -1;
        for (int i=0; i<n; i++) {
            if (customers[i] == 'Y') penalty--;
            else penalty++;
            if (penalty < minPenalty) {
                minPenalty = penalty;
                idx = i;
            }
        }
        return idx+1;
    }
};