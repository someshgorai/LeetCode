class Solution {
private:
    int countOverlap(int rowoffset, int coloffset, vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int cnt = 0;
        int n = img1.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int r2 = i + rowoffset;
                int c2 = j + coloffset;
                
                if (r2 >= 0 && r2 < n && c2 >= 0 && c2 < n) {
                    if (img1[i][j] == img2[r2][c2] && img1[i][j] == 1) cnt++;
                }
            }
        }

        return cnt;
    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxCount = 0;

        for (int i = -n+1; i < n; i++) {
            for (int j = -n+1; j < n; j++) {
                int cnt = countOverlap(i, j, img1, img2);
                maxCount = max(cnt, maxCount);
            }
        }

        return maxCount;
    }
};