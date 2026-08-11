class RecentCounter {
public:

    vector<int> pings;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        pings.push_back(t);
        int ans = 0;
        for(int i = pings.size() - 1; i>=0 ; i--)
        {   
            if(t - pings[i] <= 3000)
            ans++;
        }
        return ans;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */