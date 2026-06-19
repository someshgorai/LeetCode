class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();
        long sum = 0;
        if(n == 1) {
            for(int i=0; i<m; i++) sum += units[i][0];
            return sum;
        }
        int minFirst = INT_MAX;
        long secondSum = 0;
        for(int i=0; i<m; i++) {
            sort(units[i].begin(), units[i].end());
            minFirst = min(minFirst, units[i][0]);
            secondSum += units[i][1];
        }
        for(int i=0; i<m; i++) {
            long curr = secondSum - units[i][1] + minFirst;
            sum = max(sum, curr);
        }
        return sum;
    }
};