class Solution {
public:
    string trafficSignal(int timer) {
        if(timer > 90 || timer < 0 || (timer > 0 && timer <30))
        return "Invalid";

        else if(timer == 0)
        return "Green";

        else if(timer == 30)
        return "Orange";

        else
        return "Red";
    }
};