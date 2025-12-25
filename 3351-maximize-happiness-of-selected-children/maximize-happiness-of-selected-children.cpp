class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long totalHappiness = 0, depreciation = 0, children = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for (int i: happiness) {
            if (children == k) break;
            children++;
            int add = 0;
            if (i < depreciation) add = 0;
            else add = i - depreciation;
            totalHappiness += add;
            depreciation++;
        }
        return totalHappiness;
    }
};