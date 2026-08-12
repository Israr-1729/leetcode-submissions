class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        int idx;
        if(ruleKey == "type")
        idx = 0;

        else if(ruleKey == "color")
        idx = 1;

        else
        idx = 2;

        for(auto &a : items)
        {
            if(a[idx] == ruleValue)
            ans++;
        }
       return ans; 
    }
};