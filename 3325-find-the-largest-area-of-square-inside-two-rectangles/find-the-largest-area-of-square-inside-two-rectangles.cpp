class Solution {
private:
    long long commonSquareArea(int btx1, int bty1, int urx1, int ury1, int btx2, int bty2, int urx2, int ury2) {
        int x_overlap = min (urx2, urx1) - max (btx1, btx2);
        int y_overlap = min (ury1, ury2) - max (bty1, bty2);
        if (x_overlap <= 0 || y_overlap <= 0) return 0;
        long long side = min (x_overlap, y_overlap);
        return side * side;
    }
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxArea = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                maxArea = max(commonSquareArea(
                    bottomLeft[i][0],
                    bottomLeft[i][1],
                    topRight[i][0],
                    topRight[i][1],
                    bottomLeft[j][0],
                    bottomLeft[j][1],
                    topRight[j][0],
                    topRight[j][1]
                ), maxArea);
            }
        }
        return maxArea;
    }
};