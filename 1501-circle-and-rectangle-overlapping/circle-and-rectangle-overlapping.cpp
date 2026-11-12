class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = clamp(xCenter, x1, x2);
        int y = clamp(yCenter, y1, y2);

        return (xCenter - x) * (xCenter - x) + (yCenter - y) * (yCenter - y) <= radius * radius;
    }
};