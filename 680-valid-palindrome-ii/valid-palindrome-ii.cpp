class Solution {
public:
    bool normalPalindrome(const string &s)
    {
        int begin = 0; int end = s.size()-1;
        while(begin <= end)
        {
            if(s[begin] != s[end])
            return false;

            begin++;
            end--;
        }
        return true;
    }
    bool isPalindrome(const string &s, int index1, int index2)
    {
        string s1 = "";
        string s2 = "";

        for(int i = 0; i < s.size(); i++)
        {
            if(i == index1)
            continue;

            s1 += s[i];
        }

        for(int i = 0; i < s.size(); i++)
        {
            if(i == index2)
            continue;
            
            s2 += s[i];
        }

        return normalPalindrome(s1) || normalPalindrome(s2);
    }
    bool validPalindrome(string s) {
        int begin = 0;
        int end = s.size()-1;

        if(normalPalindrome(s))
        return true;

        while(begin <= end)
        {
            if(s[begin] != s[end])
            return isPalindrome(s, begin, end);

            begin++; end--;
        }
        
        return false;
    }
};