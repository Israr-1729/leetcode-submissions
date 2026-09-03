class Solution {
public:
    vector<string> sub(const string &s)
    {
        vector<string> result;
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = i; j < s.size(); j++)
            {
                result.push_back(s.substr(i, j-i+1));
            }
        }
        return result;
    }

    bool differByOne(const string &s1, const string &s2)
    {
        if(s1.size() != s2.size())
        return false;

        int differCount = 0;
        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] != s2[i])
            {
                differCount++;
            }

            if(differCount > 1)
            return false;
        }
        if(differCount == 0)
        return false;
        return true;
    }
    int countSubstrings(string s, string t) {
        vector<string> substringS = sub(s);
        vector<string> substringT = sub(t);

        int count = 0;
        for(int i = 0; i < substringS.size(); i++)
        {
            for(int j = 0; j < substringT.size(); j++)
            {
                if(differByOne(substringS[i], substringT[j]))
                count++;
            }
        }
        return count;
    }
};