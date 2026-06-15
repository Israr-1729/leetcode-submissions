class Solution {
public:
    string largestEven(string s) {
        int size = s.size();
        for(int i = size-1; i>=0; i--)
        {
            if(s[i]=='2')
            return s;
            else
            s.pop_back();
        }
        return s;
    }
};