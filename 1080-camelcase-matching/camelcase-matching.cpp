class Solution {
public:
    string UCOnly(const string &s)
    {
        string result = "";
        for(char c : s)
        {
            if(isupper(c))
            result += c;
        }
        return result;
    }

    vector<int> lcFreq(const string &s)
    {
        vector<int> freq(26, 0);
        for(char c : s)
        {
            if(islower(c))
            {
                freq[c-'a']++;
            }
        }
        return freq;
    }

bool compare(const string &pattern, const string &s)
{
    int i = 0;  // pattern
    int j = 0;  // query

    while (j < s.size())
    {
        if (i < pattern.size() && s[j] == pattern[i])
        {
            i++;
            j++;
        }
        else if (isupper(s[j]))
        {
            return false;
        }
        else
        {
            j++;
        }
    }

    return i == pattern.size();
}
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<int> patternFreq = lcFreq(pattern);
        string UCOnlyPattern = UCOnly(pattern);
        vector<bool> result;
        for(const string &s : queries)
        {
            //cout<<(UCOnly(s) == UCOnlyPattern)<<" "<<compare(patternFreq, s)<<"\n";
            if(UCOnly(s) == UCOnlyPattern && compare(pattern, s))
            result.push_back(true);

            else
            result.push_back(false);
        }
        return result;
    }
};