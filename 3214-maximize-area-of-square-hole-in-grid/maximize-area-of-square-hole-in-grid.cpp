class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int delH = 1, delV = 1, maxH = 1, maxV = 1;
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        for (int i=0; i<hBars.size()-1; i++) {
            if (hBars[i] == hBars[i+1] - 1) {
                delH++;
            }
            else {
                maxH = max(maxH, delH);
                delH = 1;
            }
        }
        maxH = max(maxH, delH);
        for (int i=0; i<vBars.size()-1; i++) {
            if (vBars[i] == vBars[i+1] - 1) {
                delV++;
            }
            else {
                maxV = max(maxV, delV);
                delV = 1;
            }
        }
        maxV = max(maxV, delV);
        cout << maxH << ' ' << maxV;
        int side = min(maxH, maxV) + 1;
        return side * side;
    }
};