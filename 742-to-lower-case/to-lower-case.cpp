class Solution {
public:
    char upperToLower(char c)
    {
        if(c>='A' && c<='Z')
        return c+32;

        else
        return c;
    }
    string toLowerCase(string s) {
        for(char &c : s)
        {
            c = upperToLower(c);
        }

        return s;
    }
};