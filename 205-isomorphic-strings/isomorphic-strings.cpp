class Solution {
public:
    vector<int> pattern(string str)
    {
        int size = str.size();
        unordered_map<char, int> mp;
        int idx = 0;
        vector<int> thisPattern;
        for(int i = 0; i<size; i++)
        {
            if(mp.find(str[i])!=mp.end())
            {
                thisPattern.push_back(mp[str[i]]);
            }
            else
            {
                mp[str[i]]=idx++;
                thisPattern.push_back(mp[str[i]]);
            }
        }
        return thisPattern;
    }
    bool isIsomorphic(string s, string t) {
        return pattern(s)==pattern(t);
    }
};