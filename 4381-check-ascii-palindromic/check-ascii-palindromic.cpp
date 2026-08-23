class Solution {
public:

    bool isPalindrome(const string &s)
    {
        int left = 0;
        int right = s.size()-1;

        while(left <= right)
        {
            if(s[left] != s[right])
            return false;

            left++;
            right--;
        }
        return true;
    }

    string toBinary(int num)
{
    string s = "";

    for(int i = 7; i >= 0; i--)
    {
        if(num & (1 << i))
            s += '1';
        else
            s += '0';
    }

    return s;
}

    bool isPalindromic(string s) {
        string ASCIIBinary = "";
        for(char c : s)
        {
            ASCIIBinary += toBinary(c);
        }

        return isPalindrome(ASCIIBinary);
    }
};