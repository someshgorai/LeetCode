class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int m = neededTime.size();

        vector<int> prefix(n+1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + neededTime[i];
        }

        char prev = 'A';
        int i = 0;
        int time = 0;
        while (i < n) {
            if (prev == colors[i]) {
                int start = i-1;
                int end;
                int maxTime = neededTime[start];
                while (prev == colors[i]) {
                    end = i;
                    maxTime = max(maxTime, neededTime[i]);
                    i++;
                }

                time += prefix[end+1] - prefix[start] - maxTime;
            }
            else {
                prev = colors[i];
                i++;
            }
        }

        return time;
    }
};