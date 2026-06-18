class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle = minutes * 6;
        double hourAngle = hour * 5 * 6 + 0.5 * minutes;
        double diff = abs(hourAngle - minAngle);
        return min(diff, 360 - diff);
    }
};