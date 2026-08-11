class MyCalendar {
public:
    vector<int> startTimes;
    vector<int> endTimes;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(int i = 0; i < startTimes.size(); i++)
        {
        if(startTime < endTimes[i] && endTime > startTimes[i])
            return false;

        }

        startTimes.push_back(startTime);
        endTimes.push_back(endTime);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */