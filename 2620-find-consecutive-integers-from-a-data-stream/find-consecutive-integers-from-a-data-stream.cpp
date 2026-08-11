class DataStream {
public:
    int interval;
    int val;
    int numbersSinceLastValueUnequalToVal = 0;
    DataStream(int value, int k) {
        interval = k;
        val = value;
    }
    
    bool consec(int num) {
        if(num == val)
        {
            numbersSinceLastValueUnequalToVal++;
        }

        else if(num != val)
        {
            numbersSinceLastValueUnequalToVal = 0;
        }

        if(numbersSinceLastValueUnequalToVal >= interval)
        return true;
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */