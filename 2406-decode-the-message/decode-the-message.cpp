class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char>mp;
        char begin = 'a';
        for(char c : key)
        {
            if(c==' ' || mp.find(c)!=mp.end())
            continue;
            mp[c] = begin++;
        }

        string result = "";
        for(char c : message)
        {
            if(c == ' ')
            result += " ";

            else
            result += mp[c];
        }
        return result;
    }
};