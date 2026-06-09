class Solution {
public:
    string replaceDigits(string s) {
        int size = s.size();
        for(int i = 1; i<size; i+=2)
        {
            s[i] = s[i-1] + (s[i] - '0');
        }
        return s;
    }
};