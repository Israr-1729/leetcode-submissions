class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        int sizeT = t.size();
        int sizeS = s.size();

        if(sizeS == 0)
        return true;
        for(int i = 0; i<sizeT; i++)
        {
            if(t[i]==s[idx])
            idx++;

            if(idx==sizeS)
            return true;
        }
        return false;
    }
};