class Solution {
public:
    bool checkString(string s) {
        bool bFound = false;
        int firstB = -1, lastA = -1; 

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'b' && bFound == false)
            {
            firstB = i;
            bFound = true;
            }

            if(s[i] == 'a')
            lastA = i;
        }
        if(!bFound || lastA == -1 || lastA < firstB)
        return true;
        return false;
    }
};