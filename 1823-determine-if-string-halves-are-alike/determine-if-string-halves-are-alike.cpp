class Solution {
public:

    bool isVowel(char c)
    {
        c = tolower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;

        return false;
    }
    int vowelCount(const string &s)
    {
        int count1 = 0;
        for(int i = 0; i < s.size()/2; i++)
        {
            char c = s[i];
            if(isVowel(c))
            count1++;
        }

        int count2 = 0;
        for(int i = s.size()/2; i<s.size(); i++)
        {
            char c = s[i];
            if(isVowel(c))
            count2++;
        }
        return count1 == count2;
    }
    bool halvesAreAlike(string s) {
        return vowelCount(s);
    }
};