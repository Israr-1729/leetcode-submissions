class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> from;

        for(auto &a : paths)
        {
            from.insert(a[0]);
        }

        for(auto &a : paths)
        {
            if(!from.contains(a[1]))
            return a[1];
        }
        
        return "";
    }
};