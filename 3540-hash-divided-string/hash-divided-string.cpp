class Solution {
public:

    char hashedChar(string s)
    {
        int sum = 0;
        for(char c : s)
        {
            sum += c-'a';
        }

        return ('a' + sum%26);
    }
    string stringHash(string s, int k) {
        int size = s.size();
        int idx = 0;
        string result = "";
        while(idx<size)
        {
            result += hashedChar(s.substr(idx, k));
            idx += k;
        }
        return result;
    }
};