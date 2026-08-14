class Solution {
public:
    bool max2Freq (const string &a)
    {
        vector<int> copyA(26, 0);
        vector<int> copyB(26, 0);

        for(char c : a)
        {
            copyA[c-'a']++;
            if(copyA[c-'a'] > 2)
            return false;
        }
        return true;
    }
    int maximumLengthSubstring(string s) {
        int maxLength = INT_MIN;
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = i; j < s.size(); j++)
            {
                if(max2Freq(s.substr(i, j-i+1)))
                maxLength = max(maxLength, j-i+1);
            }
        }
        return maxLength;
    }
};