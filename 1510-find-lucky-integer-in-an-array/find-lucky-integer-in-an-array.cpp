class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        
        int size = arr.size();
        for(int i = 0; i<size; i++)
        {
            freq[arr[i]]++;
        }

        vector<int> store;
        for(auto &p : freq)
        {
            if(p.first==p.second)
            store.push_back(p.first);
        }
        
        if(store.size()==0)
        return -1;

        int maxm = INT_MIN;
        for(auto val : store)
        {
            maxm = max(maxm, val);
        }
        return maxm;
    }
};