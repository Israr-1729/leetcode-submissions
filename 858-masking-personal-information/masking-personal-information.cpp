class Solution {
public:
    string maskMail(const string &s)
    {
        char firstLetter = tolower(s[0]);
        char lastLetter;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '@')
            lastLetter = tolower(s[i-1]);
        }

        string domain = "";
        bool startDomain = false;
        for(char c : s)
        {
            if(c == '@')
            startDomain = true;
            
            if(startDomain)
            domain += tolower(c);
        }

        string result = "";
        result += firstLetter;
        result += "*****";
        result += lastLetter;
        result += domain;

        return result;
    }

    string maskPhone(const string &s)
    {
        string noSeparators = "";
        for(char c : s)
        {
            if(isdigit(c))
            noSeparators += c;
        }

        string countryCode = "";
        switch(noSeparators.size())
        {
            case 10 : countryCode = ""; break;
            case 11 : countryCode = "+*-"; break;
            case 12 : countryCode = "+**-"; break;
            case 13 : countryCode = "+***-"; break;
        }

        string last = noSeparators.substr(noSeparators.size()-4, 4);

        
        return countryCode + "***-" + "***-" + last;
    }
    
    string maskPII(string s) {
        return (isalpha(s[0]) ?  maskMail(s) : maskPhone(s));
    }
};