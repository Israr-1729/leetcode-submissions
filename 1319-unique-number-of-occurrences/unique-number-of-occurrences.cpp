class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int a : arr)
        {
            mp[a]++;
        }

        unordered_set<int> check;
        for(auto &a : mp)
        {
            if(check.contains(a.second))
            return false;

            check.insert(a.second);
        }
        return true;
    }
};