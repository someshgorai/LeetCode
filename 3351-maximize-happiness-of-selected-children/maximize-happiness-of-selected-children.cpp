class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long totalHappiness = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for (int i=0; i<k; i++) {
            int curr = happiness[i] - i;
            if (curr <= 0) break; 
            totalHappiness += curr; 
        }
        return totalHappiness;
    }
};