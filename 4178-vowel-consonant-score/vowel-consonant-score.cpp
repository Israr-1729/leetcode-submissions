class Solution {
public:

    bool isvowel(char c)
    {
        if(c == 'a' || c == 'e' || c=='i' || c=='o' || c=='u')
        return true;

        return false;
    }
    int vowelConsonantScore(string s) {
        int v = 0; int con = 0;
        for(char c : s)
        {
            if(isvowel(c))
            {
                v++;
            }

            else if(isalpha(c))
            {
                con++;
            }
        }

        return con == 0 ? 0 : v/con;
        
    }
};