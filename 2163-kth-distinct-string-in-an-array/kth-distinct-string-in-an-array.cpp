class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        string result = "";
        unordered_map<string, int>mp;

        for(auto &a : arr)
        {
            mp[a]++;
        }

        unordered_set<string> distinct;
        for(auto &a : mp)
        {
            if(a.second == 1)
            distinct.insert(a.first);
        }

        if(distinct.size() < k)
        return "";

        int count = 0;

        for(auto &a : arr)
        {
            if(distinct.contains(a))
            count++;

            if(count == k)
            return a;
        }
        
        return "";
    }
};