class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int m = neededTime.size();

        char prev = 'A';
        int i = 0;
        int time = 0;
        while (i < n) {
            if (prev == colors[i]) {
                int start = i-1;
                int end;
                int maxTime = neededTime[start];
                int total = neededTime[start];
                while (prev == colors[i]) {
                    end = i;
                    total += neededTime[i];
                    maxTime = max(maxTime, neededTime[i]);
                    i++;
                }

                time += total - maxTime;
            }
            else {
                prev = colors[i];
                i++;
            }
        }

        return time;
    }
};