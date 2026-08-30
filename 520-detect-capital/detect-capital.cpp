class Solution {
public:
    bool allSmallORFirstCapital(const string &s)
    {
        for(int i = 1; i < s.size(); i++)
        {
            if(isupper(s[i]))
            return false;
        }
        return true;
    }

    bool allCapital(const string &s)
    {
        for(char c : s)
        {
            if(islower(c))
            return false;
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        if(word.size() == 1)
        return true;

        if(islower(word[1]))
        {
            return allSmallORFirstCapital(word);
        }

        if(isupper(word[1]))
        {
            return allCapital(word);
        }
        
        return false;
    }
};