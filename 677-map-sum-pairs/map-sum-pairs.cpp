class MapSum {
public:
    unordered_map<string, int> mp;
    vector<string> allKeys;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if(!mp.contains(key))
        allKeys.push_back(key);

        mp[key] = val;
    }


    int sum(string prefix) {
        int ans = 0;
        for(const string &s : allKeys)
        {
            if(s.starts_with(prefix))
            ans += mp[s];
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */