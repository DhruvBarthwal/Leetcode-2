class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12) hour = 0;
        double h = 30*hour + 0.5*minutes;
        double m = 6*minutes;
        double res = abs(h-m);
        return min(res,360-res);
    }
};