class Solution {
public:
    int binaryGap(int n) {
        int maxDist = 0, prev = -1;
        for (int i = 0; i <= 30; i++) {
            if ((n >> i) & 1) {
                if (prev != -1) maxDist = max(maxDist, i - prev
                );
                prev = i;
            }
        }
        return maxDist;
    }
};