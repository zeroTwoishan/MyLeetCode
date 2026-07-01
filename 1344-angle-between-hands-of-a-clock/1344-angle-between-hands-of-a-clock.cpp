class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (30 * hour) + (0.5 * minutes);
        double m = 6 * minutes;
        double ans = abs(h-m);
        return min(ans, 360 - ans);
    }
};