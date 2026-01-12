class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int distX = 0, distY = 0, time = 0;
        int n = points.size();
        for (int i=1; i<n; i++) {
            distX = abs(points[i-1][0] - points[i][0]);
            distY = abs(points[i-1][1] - points[i][1]);
            if (distX > distY) time += distX;
            else time += distY;
        }
        return time;
    }
};