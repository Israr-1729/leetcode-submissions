class Solution {
public:
    string final(const string &s)
    {
        string result = "";
        for(char c : s)
        {
            if(c=='#' && !(result.size()==0))
            {
                result.pop_back();
            }

            if(c != '#')
            {
                result += c;
            }
        }
        return result;
    }
    bool backspaceCompare(string s, string t) {
        return final(s) == final(t);
    }
};