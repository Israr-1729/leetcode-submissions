class Solution {
public:
    double angleClock(int hour, int minutes) {

        double hourAngle = hour*30+minutes*0.5;
        double minuteAngle = 6*minutes;

        double diff = abs(hourAngle-minuteAngle);

        return diff<180 ? diff : 360-diff;
    }
};