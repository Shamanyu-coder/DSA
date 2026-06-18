class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle=(hour%12)*30.0+minutes*0.5;
        double minutesAngle=(minutes*6.0);
        double diff=abs(hourAngle-minutesAngle);
        return min(diff,360-diff);
    }
};