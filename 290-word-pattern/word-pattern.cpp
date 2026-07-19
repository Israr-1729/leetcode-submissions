class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int size = s.size();
        int i = 0;

        vector<string> words;
        while(i<size)
        {
            string thisWord = "";
            while(i<size && s[i]!=' ')
            {
                thisWord += s[i];
                i++;
            }
        words.push_back(thisWord);
        i++;
        }
        
        if(words.size() != pattern.size())
        return false;


        unordered_map<char, string> mp; i = 0;
        for(char a : pattern)
        {
            if(mp.contains(a))
            {
                if(mp[a] != words[i++])
                return false;
            }

            else
            {
                mp[a] = words[i++];
            }
        }

        unordered_map<string, char> mp2; i = 0;
        for(string &s : words)
        {
            if(mp2.contains(s))
            {
                if(mp2[s] != pattern[i++])
                return false;
            }

            else
            {
                mp2[s] = pattern[i++];
            }
        }
        return true;
    }
};