class Solution {
public:

    string thisPattern(string s)
    {
        int idx = 'a';
        unordered_map<char, int> mp;
        int size = s.size();
        string pattern = "";

        for(int i = 0; i<size; i++)
        {
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]] = idx++;
                pattern.push_back(idx);
            }

            else
            pattern.push_back(mp[s[i]]);
        }
        return pattern;
    } 
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string simplePattern = thisPattern(pattern);
        vector<string> result;
        for(string s : words)
        {
            if(s.size()!=pattern.size())
            continue;
            if(thisPattern(s)==simplePattern)
            result.push_back(s);
        }
        return result;
    }
};