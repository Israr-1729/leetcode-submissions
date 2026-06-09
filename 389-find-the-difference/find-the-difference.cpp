class Solution {
public:
    char findTheDifference(string s, string t) {
        int xo = 0;
        int size = s.size();
        for(int i = 0; i<size; i++)
        xo = xo^s[i]^t[i];
        xo = xo^t[size];
        return xo;
    }
};