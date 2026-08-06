class TimeMap {
public:

    unordered_map<string, set<int>> TimeStampsForParticularKey;
    unordered_map<string, string> ValueForParticularKeyAfterTimeStamp; //String Of Key Will Have Timestamp Appended To It (Sometimes, my genius...)

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        TimeStampsForParticularKey[key].insert(timestamp);

        string newKey = "";
        newKey += key;
        newKey += "#";
        newKey += to_string(timestamp);

        ValueForParticularKeyAfterTimeStamp[newKey] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = TimeStampsForParticularKey[key].upper_bound(timestamp);

        if(it == TimeStampsForParticularKey[key].begin())
        return "";

        else
        {
            it--;
            int toAppend = *it;

            string newKey = "";
            newKey += key;
            newKey += "#";
            newKey += to_string(toAppend);

            return ValueForParticularKeyAfterTimeStamp[newKey];
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */