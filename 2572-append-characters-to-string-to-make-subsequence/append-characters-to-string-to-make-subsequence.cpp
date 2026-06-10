class Solution {
public:
    int appendCharacters(string s, string t) {
        int tSize = t.size();
        int sSize = s.size();
        int idx = 0;
        for(int i = 0; i<sSize; i++)
        {
            if(idx<tSize && t[idx]==s[i])
            {
                idx++;
            }
        }
        return tSize - idx;
    }
};